#ifndef ISEARCHFILTERPROXYHELPER_H
#define ISEARCHFILTERPROXYHELPER_H

class QModelIndex;
class QAbstractItemModel;
class QString;

class iSearchFilterProxyHelper
{
public:
    virtual ~iSearchFilterProxyHelper() {}
    virtual bool filterAcceptsColumn(QString type,QString filterValue,const QAbstractItemModel* model,int source_column,const QModelIndex & source_parent)=0;
    virtual bool filterAcceptsRow(QString type,QString filterValue,const QAbstractItemModel* model,int source_row,const QModelIndex & source_parent)=0;
    virtual bool lessThan(QString type,QString filterValue,const QAbstractItemModel* model,const QModelIndex & left,const QModelIndex & right)=0;
};

#endif // ISEARCHFILTERPROXYHELPER_H
