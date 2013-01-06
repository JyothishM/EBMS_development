#include "librarybutton.h"
#include "librarydialog.h"
#include "library.h"
#include <QDebug>

LibraryButton::LibraryButton(QWidget *parent) :
    QToolButton(parent)
{
    setIcon(QIcon(":/icon/resources/icons/DocuLibraryIcon.png"));
    mFileName = "library/library.xml";
    mLibContainer = new LibraryContainer();
    connect(this,
            SIGNAL(clicked()),
            this,
            SLOT(onClicked()));

//    setContextMenuPolicy(Qt::CustomContextMenu);
}

LibraryButton::~LibraryButton()
{
    delete mLibContainer;
}

void LibraryButton::setLibraryClient(iLibraryClient* client)
{
    mLibContainer->setLibraryClient(client);
}

iLibraryClient* LibraryButton::getLibraryClient()
{
    return mLibContainer->getLibraryClient();
}

void LibraryButton::setSaveFile(QString filename)
{
    mFileName = filename;
}

QString LibraryButton::getSaveFile()
{
    return mFileName;
}

bool LibraryButton::save()
{
    bool succes = mLibContainer->write(mFileName);
    return succes;
}

bool LibraryButton::load()
{
    bool succes = mLibContainer->load(mFileName);
    return succes;
}

void LibraryButton::onClicked()
{
    LibraryDialog dlg;
    dlg.setLibraryContainer(mLibContainer);
    dlg.setFileName(mFileName);
    dlg.reload();
    dlg.exec();
}
