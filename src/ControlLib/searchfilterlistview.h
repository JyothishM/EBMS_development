#ifndef SEARCHFILTERLISTVIEW_H
#define SEARCHFILTERLISTVIEW_H

#include "ControlLib_global.h"
#include <QWidget>

namespace Ui {
    class SearchFilterListView;
}

class QListView;
class QAbstractItemModel;
class SortFilterProxyModel;

class iSearchFilterProxyHelper;

class CONTROLLIBSHARED_EXPORT SearchFilterListView : public QWidget
{
    Q_OBJECT
public:
    explicit SearchFilterListView(QWidget *parent = 0);
    ~SearchFilterListView();
    QListView* getTableView();
    virtual void setModel(QAbstractItemModel* model);
    void setSearchFilterProxyHelper(iSearchFilterProxyHelper* SeachFilterHelper);
    iSearchFilterProxyHelper* getSearchFilterProxyHelper();
    void setSearchTypes(QStringList& types);
    QStringList getSearchTypes();
protected:
    virtual SortFilterProxyModel* createProxyModel(QObject* parent);
private:
    bool searchFromRow(QString type,QString value,int startRow,int endRow);

    Ui::SearchFilterListView *ui;
    SortFilterProxyModel* mSortFilterProxyModel;
    iSearchFilterProxyHelper* mSeachFilterHelper;

private slots:
    void on_btnSearch_clicked();
    void on_btnFilter_clicked();
};

#endif // SEARCHFILTERLISTVIEW_H
