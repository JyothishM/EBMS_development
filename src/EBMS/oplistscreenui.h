#ifndef OPLISTSCREENUI_H
#define OPLISTSCREENUI_H

#include <QWidget>
#include <QPushButton>
#include <QFrame>
#include <QIcon>
#include <QSize>

namespace Ui {
    class OpListScreenUi;
}

class iOpListScreen;
class iEBMS;
class QGridLayout;

class OpListScreenUi : public QWidget
{
    Q_OBJECT

public:
    explicit OpListScreenUi(iEBMS* ebms,QString screenName,QWidget *parent = 0);
    ~OpListScreenUi();
    void setEBMS(iEBMS* ebms);
    iEBMS* getEBMS();
    void setScreenName(QString screenname);
    QString getScreenName();
    void refreshUi();
signals:
    void operationRequest(QString operation,QString screen);
private slots:
    void onoperationRequested(QString operation);
private:
    QWidget* createOperationBtn(QString OpName,QIcon icon);
    void addOperationBtn(QWidget* widg,QGridLayout* layout,int row,int col);

    Ui::OpListScreenUi *ui;
    iEBMS* mEbms;
    QString mScreenName;
    QWidget* mOpBtnHolder;
};

class OpScreenBtn : public QPushButton
{
    Q_OBJECT
public:
    explicit OpScreenBtn(QWidget* parent,QString screenName="");
    ~OpScreenBtn();
    void setScreenName(QString screenname);
    QString getScreenName();
signals:
    void screenRequest(QString screenname,bool checked);
private slots:
    void onclicked(bool checked=false);
private:
    QString mScreenName;
};

class QLabel;

class OperationButton : public QFrame
{
    Q_OBJECT
public:
    explicit OperationButton(QString OpName,QIcon& icon,QWidget* parent);
    ~OperationButton();
    void setOperationName(QString OpName);
    QString getOperationName();
    void setIcon(QIcon& icon);
    QIcon& getIcon();

    static void setIconSize(QSize& size);
    static QSize& getIconSize();
signals:
    void operationRequested(QString operation);
protected:
    virtual void mousePressEvent(QMouseEvent*);
private:
    QString mOpName;
    QIcon mIcon;
    QLabel* mIconLabel;
    QLabel* mTextLabel;

    static QSize sIconSize;
};


#endif // OPLISTSCREENUI_H
