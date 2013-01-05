#ifndef OPCOMPANYSTRUCTPLUGIN_H
#define OPCOMPANYSTRUCTPLUGIN_H

#include <QObject>
#include "opCompanyStruct_global.h"
#include "iOperationPlugin.h"

class OPCOMPANYSTRUCTSHARED_EXPORT OpCompanyStructPlugin : public QObject,
                                                            public iOperationPlugin
{
    Q_OBJECT
    Q_INTERFACES(iOperationPlugin)
public:
    explicit OpCompanyStructPlugin(QObject *parent = 0);
    virtual ~OpCompanyStructPlugin();

    // iOperationPlugin interface
    virtual QString getPluginName();
    virtual QList<iOperationDetail*> createOpDetails();
};

#endif // OPCOMPANYSTRUCTPLUGIN_H
