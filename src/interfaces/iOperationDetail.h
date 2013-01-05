#ifndef IOPERATIONDETAIL_H
#define IOPERATIONDETAIL_H

#include <QObject>

class iOperation;
class QWidget;
class QIcon;

class iOperationDetail
{
public:
    virtual ~iOperationDetail() {}
    virtual QString getOpName()=0;
    virtual QString getOpVersion()=0;
    virtual QIcon getIcon()=0;
    virtual QWidget* createScreen(QString type)=0;
};

Q_DECLARE_INTERFACE(iOperationDetail,
                     "com.vismayainfotech.iOperationDetail/1.0")

#endif // IOPERATIONDETAIL_H
