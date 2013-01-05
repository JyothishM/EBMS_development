#include "sortfilterproxymodel.h"
#include "iSearchFilterProxyHelper.h"

SortFilterProxyModel::SortFilterProxyModel(QObject *parent) :
    QSortFilterProxyModel(parent)
{
    mSearchFilterHelper = 0;
}

SortFilterProxyModel::~SortFilterProxyModel()
{

}

void SortFilterProxyModel::setSearchFilterProxyHelper(iSearchFilterProxyHelper* SearchFilterHelper)
{
    mSearchFilterHelper = SearchFilterHelper;
}

iSearchFilterProxyHelper* SortFilterProxyModel::getSearchFilterProxyHelper()
{
    return mSearchFilterHelper;
}

void SortFilterProxyModel::setSearchType(QString type)
{
    mSearchType = type;
}

QString SortFilterProxyModel::getSearchType()
{
    return mSearchType;
}

void SortFilterProxyModel::setSearchString(QString string)
{
    mSearchString = string;
}

QString SortFilterProxyModel::getSeachString()
{
    return mSearchString;
}

void SortFilterProxyModel::filter()
{
    setFilterFixedString(mSearchString);
}

bool SortFilterProxyModel::filterAcceptsColumn(int source_column,const QModelIndex & source_parent) const
{
    bool result=false;
    if(!mSearchFilterHelper)
        result = QSortFilterProxyModel::filterAcceptsColumn(source_column,source_parent);
    else
    {
        result = mSearchFilterHelper->filterAcceptsColumn(mSearchType,
                                                          mSearchString,
                                                          this,
                                                          source_column,
                                                          source_parent);         // Todo: needs to be modified
    }
    return result;
}

bool SortFilterProxyModel::filterAcceptsRow( int source_row, const QModelIndex & source_parent) const
{
    bool result=false;
    if(!mSearchFilterHelper)
        result = QSortFilterProxyModel::filterAcceptsRow(source_row,source_parent);
    else
    {
        result = mSearchFilterHelper->filterAcceptsRow(mSearchType,
                                                      mSearchString,
                                                      this,
                                                      source_row,
                                                      source_parent);         // Todo: needs to be modified
    }
    return result;
}

bool SortFilterProxyModel::lessThan( const QModelIndex & left, const QModelIndex & right) const
{
    bool result=false;
    if(!mSearchFilterHelper)
        result = QSortFilterProxyModel::lessThan(left,right);
    else
    {
        result = mSearchFilterHelper->lessThan(mSearchType,
                                              mSearchString,
                                              this,
                                              left,
                                              right);         // Todo: needs to be modified
    }
    return result;
}
