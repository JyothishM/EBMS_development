#include "searchfilterlistview.h"
#include "ui_searchfilterlistview.h"
#include "iSearchFilterProxyHelper.h"
#include "sortfilterproxymodel.h"
#include <QDebug>

SearchFilterListView::SearchFilterListView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SearchFilterListView)
{
    ui->setupUi(this);
    mSortFilterProxyModel = 0;
}

SearchFilterListView::~SearchFilterListView()
{
    delete ui;
}

QListView* SearchFilterListView::getListView()
{
    return ui->listView;
}

void SearchFilterListView::setModel(QAbstractItemModel* model)
{
    if(!mSortFilterProxyModel)
        mSortFilterProxyModel = createProxyModel(this);   // if not already created create one.

    mSortFilterProxyModel->setSourceModel(model);
    ui->listView->setModel(mSortFilterProxyModel);
}

void SearchFilterListView::setSearchFilterProxyHelper(iSearchFilterProxyHelper* SeachFilterHelper)
{
    if(mSortFilterProxyModel)
    {
        mSortFilterProxyModel->setSearchFilterProxyHelper(SeachFilterHelper);
    }
}

iSearchFilterProxyHelper* SearchFilterListView::getSearchFilterProxyHelper()
{
    if(mSortFilterProxyModel)
        return mSortFilterProxyModel->getSearchFilterProxyHelper();

    return 0;
}

void SearchFilterListView::setSearchTypes(QStringList& types)
{
    ui->ComboType->clear();
    ui->ComboType->addItems(types);
}

QStringList SearchFilterListView::getSearchTypes()
{
    QStringList items;
    const int count = ui->ComboType->count();
    for(int i=0; i<count; i++)
    {
        items.append(ui->ComboType->itemText(i));
    }
    return items;
}

QVariant SearchFilterListView::selectedValue(bool* ok)
{
    bool succes = false;
    QVariant val;
    if(mSortFilterProxyModel)
    {
        QItemSelectionModel* selModel = ui->listView->selectionModel();
        if(selModel)
        {
            QModelIndexList indexList = selModel->selectedIndexes();
            if(!indexList.isEmpty())
            {
                QModelIndex index = indexList.first();
                //QModelIndex SourceIndex = mSortFilterProxyModel->mapToSource(index);
                val = mSortFilterProxyModel->data(index);
                succes = true;
            }
        }
//        QModelIndex index = ui->listView->currentIndex();
//        val = mSortFilterProxyModel->data(index);
//        succes = true;
    }

    if(ok)
    {
        *ok = succes;
    }

    return val;
}

SortFilterProxyModel* SearchFilterListView::createProxyModel(QObject* parent)
{
    return new SortFilterProxyModel(parent);
}

bool SearchFilterListView::searchFromRow(QString type,QString value,int startRow,int endRow)    // Todo: type needs to be considered
{
    bool succes=false;
    QItemSelectionModel* selModel = ui->listView->selectionModel();

    const int rowcount =  mSortFilterProxyModel->rowCount();

    startRow = startRow>=0 ? startRow : 0;
    endRow = endRow<rowcount ? endRow : rowcount-1;
    iSearchFilterProxyHelper* searchHelper = getSearchFilterProxyHelper();
    QModelIndex foundIndex;
    for(int row=startRow;row<=endRow;row++)
    {
        QModelIndex curIndex = mSortFilterProxyModel->index(row,0);
        if(searchHelper)
        {
            succes = searchHelper->filterAcceptsRow(type,
                                                    value,
                                                    mSortFilterProxyModel->sourceModel(),
                                                    mSortFilterProxyModel->mapToSource(curIndex).row(),
                                                    QModelIndex());
        }
        else
        {
            succes = (0 == mSortFilterProxyModel->data(curIndex).toString().compare(value,Qt::CaseInsensitive));
        }

        if(succes)
        {
            foundIndex = curIndex;
            break;
        }
    }
    if(foundIndex.isValid())
    {
        selModel->setCurrentIndex(foundIndex,QItemSelectionModel::Select);
        ui->listView->scrollTo(foundIndex);
        succes = true;
    }
    return succes;
}

void SearchFilterListView::on_btnFilter_clicked()
{
    if(!mSortFilterProxyModel)
        return;

    QString filterStr = ui->edtFilterStr->text();
    QString seachType = ui->ComboType->currentText();
    mSortFilterProxyModel->setSearchType(seachType);
    mSortFilterProxyModel->setSearchString(filterStr);
    mSortFilterProxyModel->filter();
}

void SearchFilterListView::on_btnSearch_clicked()
{
    if(!mSortFilterProxyModel)
        return;

    QItemSelectionModel* selModel = ui->listView->selectionModel();
    if(selModel)
    {
        QModelIndex curSelIndex = selModel->currentIndex();
        int row = 0;
        if(curSelIndex.isValid())
        {
            row = curSelIndex.row() + 1;
        }
        ui->listView->clearSelection();
        QString filterStr = ui->edtFilterStr->text();
        QString type = ui->ComboType->currentText();
        mSortFilterProxyModel->setSearchType(type);
        mSortFilterProxyModel->setSearchString(filterStr);
        bool succes = searchFromRow(type,filterStr,row,mSortFilterProxyModel->rowCount()-1);
        if(!succes)
        {
           searchFromRow(type,filterStr,0,row);
        }
    }
}
