#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "librarybutton.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow,
                    public LibButton::iLibraryClient
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    virtual LibButton::iLibrary* createLibrary();
    virtual bool fillLibrary(LibButton::iLibrary* lib);
    virtual bool setLibrary(LibButton::iLibrary* lib);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
