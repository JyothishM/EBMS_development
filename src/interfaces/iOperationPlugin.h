#ifndef IOPERATIONPLUGIN_H
#define IOPERATIONPLUGIN_H

#include <QObject>

class iOperationDetail;

class iOperationPlugin
{
public:
    virtual ~iOperationPlugin() {}
    virtual QString getPluginName()=0;
    virtual QList<iOperationDetail*> createOpDetails()=0;
};

Q_DECLARE_INTERFACE(iOperationPlugin,
                     "com.vismayainfotech.iOperationPlugin/1.0")


#endif // IOPERATIONPLUGIN_H
