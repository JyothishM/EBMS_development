#ifndef IOPLISTSCREEN_H
#define IOPLISTSCREEN_H

#include <QObject>
#include <QList>

class QDomNode;
class iOperationDetail;

class iOpListScreen
{
public:
    virtual ~iOpListScreen() {}
    virtual void appendOperation(QString oper)=0;
    virtual void insertOperation(int index,QString oper)=0;
    virtual int getOpCount()=0;
    virtual QString getOperationAt(int index)=0;
    virtual QStringList getOpList()=0;

    // saving and loading
    virtual bool saveUiDetail(QDomNode& node)=0;
    virtual bool refreshUiDetail(QDomNode& node)=0;

    virtual void clearOpList()=0;
    virtual void setScreenName(QString name)=0;
    virtual QString getScreenName()=0;
    virtual void setScreenType(QString name)=0;
    virtual QString getScreenType()=0;
};

Q_DECLARE_INTERFACE(iOpListScreen,
                     "com.vismayainfotech.iOpListScreen/1.0")

#endif // IOPLISTSCREEN_H
