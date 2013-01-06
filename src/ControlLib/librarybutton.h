#ifndef LIBRARYBUTTON_H
#define LIBRARYBUTTON_H

#include "ControlLib_global.h"
#include <QToolButton>
#include <QHash>


class iLibrary;
class iLibraryClient;
class iLibraryContainer;


class CONTROLLIBSHARED_EXPORT LibraryButton : public QToolButton
{
    Q_OBJECT
public:
    explicit LibraryButton(QWidget *parent = 0);
    virtual ~LibraryButton();
    void setLibraryClient(iLibraryClient* client);
    iLibraryClient* getLibraryClient();
    void setSaveFile(QString filename);
    QString getSaveFile();
    bool save();
    bool load();
private slots:
    void onClicked();
private:
    QString mFileName;
    iLibraryContainer* mLibContainer;
};

#endif // LIBRARYBUTTON_H
