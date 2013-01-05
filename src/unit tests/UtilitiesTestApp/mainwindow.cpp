#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "orderedhash.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    testOrderedHash();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::testOrderedHash()
{
    qDebug() << "test starting";

    OrderedHash<QString,int> myhash;
    myhash.append("ccc",1);
    myhash.append("aaa",2);
    myhash.append("bbb",3);
    qDebug() << myhash.keys() << myhash.values();
    myhash.insert("mmm",10,1);
    qDebug() << myhash.keys() << myhash.values();
    qDebug() << "ordered form" << myhash.orderedKeys() << myhash.orderedValues();
}
