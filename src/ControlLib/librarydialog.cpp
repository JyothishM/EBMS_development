#include "librarydialog.h"
#include "ui_librarydialog.h"
#include "iLibrary.h"
#include <QMessageBox>
#include <QInputDialog>
#include <QStandardItemModel>
#include <QVariant>

LibraryDialog::LibraryDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LibraryDialog)
{
    ui->setupUi(this);
    mLibContainer = 0;
    mLibModel = new QStandardItemModel(this);
    ui->libraryListView->setModel(mLibModel);
}

LibraryDialog::~LibraryDialog()
{
    delete ui;
}

void LibraryDialog::setFileName(QString filename)
{
    mFileName = filename;
}

QString LibraryDialog::getFileName()
{
    return mFileName;
}

void LibraryDialog::setLibraryContainer(iLibraryContainer* LibContainer)
{
    mLibContainer = LibContainer;
}

iLibraryContainer* LibraryDialog::getLibraryContainer()
{
    return mLibContainer;
}

//   public slots

void LibraryDialog::refreshUi()     // Not implimented
{
    mLibModel->clear();
    if(!mLibContainer)
        return;
    QStringList libraries = mLibContainer->getLibraryNames();
    foreach(QString libName,libraries)
    {
        QStandardItem* item = new QStandardItem(libName);
        mLibModel->appendRow(item);
    }
}

void LibraryDialog::reload()
{
    load();
    refreshUi();
}

// private slots

void LibraryDialog::on_btnSaveAsLibrary_clicked()
{
    QString libName = QInputDialog::getText(this,
                          tr("Create library"),
                          tr("Enter new library name"));

    // validate here

    iLibrary* lib = createLibrary();
    if(lib)
    {
        if(fillLibrary(lib))
        {
            lib->setName(libName); // read name
            if(addLibrary(lib))
            {
                save();
                reload();
            }
        }
        else
        {
            delete lib;
            QMessageBox::critical(this,
                                  tr("Error"),
                                  tr("Could not fill values in library"));
        }
    }
    else
    {
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("Could not create library"));
    }
}


void LibraryDialog::on_btnRemove_clicked()
{
    if(!mLibContainer)
        return;

    QString libName = selectedLibrary();
    if(removeLibrary(libName))
    {
        save();
        refreshUi();
    }
}

void LibraryDialog::on_btnApply_clicked()        // Not implimented
{
    QString libName = selectedLibrary();
    iLibrary* lib = getLibrary(libName);
    if(lib)
    {
        if(applyLibrary(lib))
        {
            QMessageBox::information(this,
                                  tr("Library set"),
                                  tr("Library succesfully applied"));
        }
        else
        {
            QMessageBox::critical(this,
                                  tr("Error"),
                                  tr("Could not apply library"));
        }
    }
}

///////////////////private////////////////////////////////////////////////
bool LibraryDialog::fillLibrary(iLibrary* lib)
{
    if(!mLibContainer || !lib)
        return false;
    iLibraryClient* LibClient = mLibContainer->getLibraryClient();
    if(!LibClient)
        return false;

    bool succes=false;
    succes = LibClient->fillLibrary(lib);
    return succes;
}

bool LibraryDialog::applyLibrary(iLibrary* lib)
{
    if(!mLibContainer || !lib)
        return false;
    iLibraryClient* LibClient = mLibContainer->getLibraryClient();
    if(!LibClient)
        return false;

    bool succes = LibClient->setLibrary(lib);
    return succes;
}

bool LibraryDialog::addLibrary(iLibrary* lib)
{
    if(!mLibContainer || !lib)
        return false;

    bool succes = mLibContainer->addLibrary(lib);
    return succes;
}

bool LibraryDialog::removeLibrary(QString name)
{
    if(!mLibContainer)
        return false;

    bool succes = mLibContainer->removeLibrary(name);
    return succes;
}

iLibrary* LibraryDialog::createLibrary()
{
    if(!mLibContainer)
        return 0;
    iLibraryClient* LibClient = mLibContainer->getLibraryClient();
    if(!LibClient)
        return 0;

    iLibrary* lib = LibClient->createLibrary();
    return lib;
}

iLibrary* LibraryDialog::getLibrary(QString name)
{
    if(!mLibContainer)
        return 0;

    iLibrary* lib = mLibContainer->getLibrary(name);
    return lib;
}

QString LibraryDialog::selectedLibrary()
{
    bool ok=false;
    QVariant val = ui->libraryListView->selectedValue(&ok);
    QString libName = val.toString();
    if(!ok)
    {
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("Could not find any proper library selected..!"));
    }
    return libName;
}

bool LibraryDialog::save()
{
    if(!mLibContainer || mFileName.isEmpty())
        return false;

    bool succes = mLibContainer->write(mFileName);
    return succes;
}

bool LibraryDialog::load()
{
    if(!mLibContainer || mFileName.isEmpty())
        return false;

    bool succes = mLibContainer->load(mFileName);
    return succes;
}

