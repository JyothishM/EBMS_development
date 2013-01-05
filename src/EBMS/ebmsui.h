#ifndef EBMSUI_H
#define EBMSUI_H

#include <QMainWindow>
#include <QHash>

namespace Ui {
    class EBMSui;
}

class iEBMS;

class EBMSui : public QMainWindow
{
    Q_OBJECT

public:
    explicit EBMSui(QWidget *parent = 0);
    ~EBMSui();
private slots:
    void ontabCloseRequested(int index);
    void onscreenRequest(QString screenname,bool checked);
    void onoperationRequested(QString operation);
private:
    void refreshUi();
    void removeScreenWidget(QWidget* widg);

    Ui::EBMSui *ui;
    iEBMS* mEbms;
    QList<QWidget*> mOpScreenBtnList;
    QHash<QString,QWidget*> mScreenWidgets;
};

#endif // EBMSUI_H
