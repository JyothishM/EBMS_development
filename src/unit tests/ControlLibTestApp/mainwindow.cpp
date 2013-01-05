#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QStandardItemModel>
#include "iSearchFilterProxyHelper.h"
#include "sortfilterproxymodel.h"


class TestSearchHelper : public iSearchFilterProxyHelper
{
public:
    TestSearchHelper() {}
    virtual ~TestSearchHelper() {}
    virtual bool filterAcceptsColumn(QString type,QString filterValue,const QAbstractItemModel* model,int source_column,const QModelIndex & source_parent)
    {
        return true;
    }

    virtual bool filterAcceptsRow(QString type,QString filterValue,const QAbstractItemModel* model,int source_row,const QModelIndex & source_parent)
    {
        if(filterValue.isEmpty())
            return true;
        bool succes = false;
        QModelIndex index0 = model->index(source_row,0, source_parent);
        QString value = model->data(index0).toString();
        if(type == "value")
            succes = value==filterValue;
        else if(type == "value+1")
            succes = value==(filterValue+"1");
        return succes;
    }

    virtual bool lessThan(QString type,QString filterValue,const QAbstractItemModel* model,const QModelIndex & left,const QModelIndex & right)
    {
        return false;
    }
};


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->toolButton->setLibraryClient(this);


    QStandardItemModel* model = new QStandardItemModel(4, 3);
     for (int row = 0; row < 4; ++row) {
         for (int column = 0; column < 3; ++column) {
             QStandardItem *item = new QStandardItem(QString("row%0 col%1").arg(row).arg(column));
             model->setItem(row, column, item);
         }
     }

     ui->sortFilterList->setModel(model);

     QStringList sortFilterTypes;
     sortFilterTypes << "value" << "value+1";
     ui->sortFilterList->setSearchTypes(sortFilterTypes);
     ui->sortFilterList->setSearchFilterProxyHelper(new TestSearchHelper());

}

MainWindow::~MainWindow()
{
    delete ui;
}

LibButton::iLibrary* MainWindow::createLibrary()
{
    return new LibButton::Library();
}

bool MainWindow::fillLibrary(LibButton::iLibrary* lib)
{
    if(!lib)
        return false;
    for(int i=0; i< 5; i++)
    {
        lib->setValue(QString("key %0").arg(i),QString("value %0").arg(i));
    }
    return true;
}

bool MainWindow::setLibrary(LibButton::iLibrary* lib)
{
    foreach(QString key,lib->getKeys())
    {
        qDebug() << key << " = " << lib->toString(key,lib->getValue(key));
    }
    return true;
}
