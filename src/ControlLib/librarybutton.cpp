#include "librarybutton.h"
#include <QDebug>

LibraryButton::LibraryButton(QWidget *parent) :
    QToolButton(parent)
{
    setIcon(QIcon(":/icon/resources/icons/DocuLibraryIcon.png"));
    mLibClient = 0;

    mFileName = "library/library.xml";

    // temp
    connect(this,
            SIGNAL(clicked()),
            this,
            SLOT(createLibrary()));

    setContextMenuPolicy(Qt::CustomContextMenu);

    connect(this,
            SIGNAL(customContextMenuRequested(QPoint)),
            this,
            SLOT(setLibrayValues()));
}

LibraryButton::~LibraryButton()
{

}

void LibraryButton::setLibraryClient(LibButton::iLibraryClient* client)
{
    mLibClient = client;
}

LibButton::iLibraryClient* LibraryButton::getLibraryClient()
{
    return mLibClient;
}

void LibraryButton::setSaveFile(QString filename)
{
    mFileName = filename;
}

QString LibraryButton::getSaveFile()
{
    return mFileName;
}

bool LibraryButton::save()   // not implimented
{
    return false;
}

bool LibraryButton::load()  // not implimented
{
    return false;
}

void LibraryButton::createLibrary()
{
    if(!mLibClient)
        return;

    LibButton::iLibrary* lib = mLibClient->createLibrary();
    if(lib)
    {
        if(mLibClient->fillLibrary(lib))
        {
            QString name = "newlib";         // Todo needs to be modified by reading value from the user
            mLibraryHash.insert(name,lib);
        }
        else
            delete lib;
    }
}

void LibraryButton::setLibrayValues()
{
    if(mLibraryHash.count() > 0)
    {
        LibButton::iLibrary* lib = mLibraryHash.value("newlib");   // Todo: needs to be modified.
        if(mLibClient && lib)
        {
            if(mLibClient->setLibrary(lib))
            {
                qDebug() << "succesfully library values are copied";
            }
            else
                qDebug() << "could not copy library values";
        }
    }
}

//////////////////Library//////////////////////////////////////////////////////
namespace LibButton
{

Library::Library()
{

}

Library::~Library()
{

}

void Library::setValue(QString name,QVariant value)
{
    if(!name.isEmpty())
        mValueHash.insert(name,value.toString());
}

QVariant Library::getValue(QString name)
{
    return mValueHash.value(name);
}

QString Library::toString(QString /*name*/,QVariant value)
{
    return value.toString();
}

QVariant Library::fromString(QString /*name*/,QString value)
{
    return value;
}

QStringList Library::getKeys()
{
    return mValueHash.keys();
}

} // namespace LibButton
