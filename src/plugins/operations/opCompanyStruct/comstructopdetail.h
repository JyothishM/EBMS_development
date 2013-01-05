#ifndef COMSTRUCTOPDETAIL_H
#define COMSTRUCTOPDETAIL_H

#include "iOperationDetail.h"

class ComStructOpDetail : public iOperationDetail
{
    Q_INTERFACES(iOperationDetail)
public:
    ComStructOpDetail();
    virtual ~ComStructOpDetail();

    // iOperationDetail interface
    virtual QString getOpName();
    virtual QString getOpVersion();
    virtual QIcon getIcon();
    virtual QWidget* createScreen(QString type=QString());
};

#endif // COMSTRUCTOPDETAIL_H
