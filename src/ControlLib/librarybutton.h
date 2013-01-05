#ifndef LIBRARYBUTTON_H
#define LIBRARYBUTTON_H

#include "ControlLib_global.h"
#include <QToolButton>
#include <QHash>
#include <QVariant>
#include <QStringList>

namespace LibButton
{
class iLibrary;
class iLibraryClient;
}


class CONTROLLIBSHARED_EXPORT LibraryButton : public QToolButton
{
    Q_OBJECT
public:
    explicit LibraryButton(QWidget *parent = 0);
    virtual ~LibraryButton();
    void setLibraryClient(LibButton::iLibraryClient* client);
    LibButton::iLibraryClient* getLibraryClient();
    void setSaveFile(QString filename);
    QString getSaveFile();
    bool save();
    bool load();
public slots:
    void createLibrary();
    void setLibrayValues();
private:
    LibButton::iLibraryClient* mLibClient;
    QString mFileName;
    QHash<QString,LibButton::iLibrary*> mLibraryHash;
};

namespace LibButton
{


class iLibrary
{
public:
    virtual ~iLibrary() {}
    virtual void setValue(QString name,QVariant value)=0;
    virtual QVariant getValue(QString name)=0;
    virtual QString toString(QString name,QVariant value)=0;
    virtual QVariant fromString(QString name,QString value)=0;
    virtual QStringList getKeys()=0;
};

class iLibraryClient
{
public:
    virtual ~iLibraryClient() {}
    virtual iLibrary* createLibrary()=0;
    virtual bool fillLibrary(iLibrary* lib)=0;
    virtual bool setLibrary(iLibrary* lib)=0;
};

class CONTROLLIBSHARED_EXPORT Library : public iLibrary
{
public:
    explicit Library();
    virtual ~Library();
    virtual void setValue(QString name,QVariant value);
    virtual QVariant getValue(QString name);
    virtual QString toString(QString name,QVariant value);
    virtual QVariant fromString(QString name,QString value);
    virtual QStringList getKeys();
private:
    QHash<QString,QString> mValueHash;
};

} // namespace LibButton

#endif // LIBRARYBUTTON_H
