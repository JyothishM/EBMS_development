#include "oplistscreenui.h"
#include "ui_oplistscreenui.h"
#include "iOpListScreen.h"
#include "iEBMS.h"
#include "iOperationDetail.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QGraphicsColorizeEffect>

OpListScreenUi::OpListScreenUi(iEBMS* ebms,QString screenName,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OpListScreenUi)
{
    ui->setupUi(this);
    mEbms = ebms;
    mScreenName = screenName;

    mOpBtnHolder = new QWidget(this);
    ui->scrollArea->setWidget(mOpBtnHolder);

    refreshUi();
}

OpListScreenUi::~OpListScreenUi()
{
    delete ui;
}

void OpListScreenUi::setEBMS(iEBMS* ebms)
{
    mEbms = ebms;
}

iEBMS* OpListScreenUi::getEBMS()
{
    return mEbms;
}

void OpListScreenUi::setScreenName(QString screenname)
{
    mScreenName = screenname;
}

QString OpListScreenUi::getScreenName()
{
    return mScreenName;
}

void OpListScreenUi::refreshUi()
{
    if(!mEbms)
        return;
    iOpListScreen* oplistscreen = mEbms->getOpListScreen(mScreenName);
    if(!oplistscreen)
        return;

    qDeleteAll(mOpBtnHolder->children());   // clearing prev buttons
    QGridLayout* layout = new QGridLayout(mOpBtnHolder);
    int r=0,c=0;
    foreach(QString opName,oplistscreen->getOpList())
    {
        iOperationDetail* opDetail = mEbms->getOperationDetail(opName);
        if(opDetail)
        {
            addOperationBtn(createOperationBtn(opName,opDetail->getIcon()),
                            layout,
                            r,
                            c++);

            if(c >= 3)
            {
                r++;
                c=0;
            }
        }
    }

    mOpBtnHolder->setLayout(layout);
}

void OpListScreenUi::onoperationRequested(QString operation)
{
    emit operationRequest(operation,mScreenName);
}

QWidget* OpListScreenUi::createOperationBtn(QString OpName,QIcon icon)
{
    return new OperationButton(OpName,
                               icon,
                               this);
}

void OpListScreenUi::addOperationBtn(QWidget* widg,QGridLayout* layout,int row,int col)
{
    layout->addWidget(widg,
                      row,
                      col,
                      Qt::AlignLeft | Qt::AlignTop);
    connect(widg,
            SIGNAL(operationRequested(QString)),
            this,
            SLOT(onoperationRequested(QString)));
}

///////////////OpScreenBtn//////////////////////////////////
OpScreenBtn::OpScreenBtn(QWidget* parent,QString screenName)
    : QPushButton(parent)
{
    setScreenName(screenName);
    connect(this,
            SIGNAL(clicked(bool)),
            this,
            SLOT(onclicked(bool)));
}

OpScreenBtn::~OpScreenBtn()
{

}

void OpScreenBtn::setScreenName(QString screenname)
{
    mScreenName = screenname;
}

QString OpScreenBtn::getScreenName()
{
    return mScreenName;
}

void OpScreenBtn::onclicked(bool checked)
{
    emit screenRequest(mScreenName,checked);
}

/////////////////////OperationButton//////////////////////////////////////
QSize OperationButton::sIconSize = QSize(40,40);

OperationButton::OperationButton(QString OpName,QIcon& icon,QWidget* parent)
    : QFrame(parent)
{
    mIconLabel = new QLabel(this);
    mTextLabel = new QLabel(this);
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(mIconLabel);
    layout->addWidget(mTextLabel);
    setLayout(layout);

    setOperationName(OpName);
    setIcon(icon);

    setFrameStyle(QFrame::StyledPanel);
    setFrameShadow(QFrame::Raised);
}

OperationButton::~OperationButton()
{

}

void OperationButton::setOperationName(QString OpName)
{
    mOpName = OpName;
    mTextLabel->setText(mOpName);
}

QString OperationButton::getOperationName()
{
    return mOpName;
}

void OperationButton::setIcon(QIcon& icon)
{
    mIcon = icon;
    mIconLabel->setPixmap(mIcon.pixmap(sIconSize));
}

QIcon& OperationButton::getIcon()
{
    return mIcon;
}

void OperationButton::setIconSize(QSize& size)
{
    sIconSize = size;
}

QSize& OperationButton::getIconSize()
{
    return sIconSize;
}

void OperationButton::mousePressEvent(QMouseEvent* event)
{
    emit operationRequested(mOpName);
    QFrame::mousePressEvent(event);
}
