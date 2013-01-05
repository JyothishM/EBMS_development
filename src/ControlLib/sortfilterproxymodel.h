#ifndef SORTFILTERPROXYMODEL_H
#define SORTFILTERPROXYMODEL_H

#include "ControlLib_global.h"
#include <QSortFilterProxyModel>

class iSearchFilterProxyHelper;

class CONTROLLIBSHARED_EXPORT SortFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    explicit SortFilterProxyModel(QObject *parent = 0);
    virtual ~SortFilterProxyModel();
    void setSearchFilterProxyHelper(iSearchFilterProxyHelper* SearchFilterHelper);
    iSearchFilterProxyHelper* getSearchFilterProxyHelper();
    void setSearchType(QString type);
    QString getSearchType();
    void setSearchString(QString string);
    QString getSeachString();
    void filter();
protected:
    virtual bool filterAcceptsColumn(int source_column,const QModelIndex& source_parent) const;
    virtual bool filterAcceptsRow(int source_row,const QModelIndex& source_parent) const;
    virtual bool lessThan(const QModelIndex& left,const QModelIndex& right) const;
private:
    iSearchFilterProxyHelper* mSearchFilterHelper;
    QString mSearchType;
    QString mSearchString;
};

#endif // SORTFILTERPROXYMODEL_H
