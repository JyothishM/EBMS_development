#include "ebmsui.h"
#include "ui_ebmsui.h"
#include "ebms.h"
#include "oplistscreenui.h"
#include "iOperationDetail.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>

EBMSui::EBMSui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EBMSui)
{
    ui->setupUi(this);
    mEbms = new EBMS(this);
    mEbms->setOpPluginPaths(QStringList() << "plugins/operations/");
    mEbms->refreshOpDetails();
    refreshUi();

    // test
//    mEbms->saveUiDetail();
//    mEbms->refreshUiDetail();
//    refreshUi();

    if(ui->splitter->count() >= 2)
    {
        QList<int> sizes;
        sizes << 40 << 400;
        ui->splitter->setSizes(sizes);
    }
}

EBMSui::~EBMSui()
{
    delete ui;
}

// private slots
void EBMSui::ontabCloseRequested(int index)
{
    QWidget* widg = ui->tabWidget->widget(index);
    removeScreenWidget(widg);
    ui->tabWidget->removeTab(index);
    delete widg;
}

void EBMSui::onscreenRequest(QString screenname,bool checked)
{
    if(!mEbms)
        return;
    if(mScreenWidgets.contains(screenname))
    {
        int index = ui->tabWidget->indexOf(mScreenWidgets.value(screenname));
        ui->tabWidget->setCurrentIndex(index);
    }
    else
    {
        OpListScreenUi* optScreen = new OpListScreenUi(mEbms,screenname,this);
        int index = ui->tabWidget->addTab(optScreen,screenname);
        ui->tabWidget->setCurrentIndex(index);
        mScreenWidgets.insert(screenname,optScreen);

        connect(optScreen,
                SIGNAL(operationRequest(QString,QString)),
                this,
                SLOT(onoperationRequested(QString)));
    }
}

void EBMSui::onoperationRequested(QString operation)
{
    if(!mEbms)
        return;

    iOperationDetail* opDetail = mEbms->getOperationDetail(operation);
    if(opDetail)
    {
        QWidget* widg = opDetail->createScreen("");  // Todo: type needs to be passed.
        if(widg)
        {
            int index = ui->tabWidget->addTab(widg,opDetail->getIcon(),operation);
            ui->tabWidget->setCurrentIndex(index);
        }
    }
}

void EBMSui::removeScreenWidget(QWidget* widg)
{
    OpListScreenUi* screenui = dynamic_cast<OpListScreenUi*>(widg);
    if(screenui)
    {
        mScreenWidgets.remove(screenui->getScreenName());
    }
}

// private
void EBMSui::refreshUi()
{
    // remove previous
    QLayout* curLayout = ui->OpListBtnWidget->layout();
    if(curLayout)
    {
        qDebug() << "deleting layout";
        qDeleteAll(mOpScreenBtnList);
        delete curLayout;
    }

    mOpScreenBtnList.clear();
    QVBoxLayout* newlayout = new QVBoxLayout();
    foreach(QString opListScreenName, mEbms->getOpListScreenNames())
    {
        OpScreenBtn* btn = new OpScreenBtn(this,opListScreenName);
        btn->setText(opListScreenName);
        newlayout->addWidget(btn);
        mOpScreenBtnList.append(btn);

        connect(btn,
                SIGNAL(screenRequest(QString,bool)),
                this,
                SLOT(onscreenRequest(QString,bool)));
    }
    ui->OpListBtnWidget->setLayout(newlayout);

    const int count = ui->tabWidget->count();
    for(int i=0; i<count; i++)
    {
        ontabCloseRequested(0);
    }
}

