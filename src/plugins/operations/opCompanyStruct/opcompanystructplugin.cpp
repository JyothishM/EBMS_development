#include "opcompanystructplugin.h"
#include "comstructopdetail.h"
#include <QtPlugin>

OpCompanyStructPlugin::OpCompanyStructPlugin(QObject *parent) :
    QObject(parent)
{
}

OpCompanyStructPlugin::~OpCompanyStructPlugin()
{

}

QString OpCompanyStructPlugin::getPluginName()
{
    return "OpCompanyStructPlugin";
}

QList<iOperationDetail*> OpCompanyStructPlugin::createOpDetails()
{
    QList<iOperationDetail*> opDetailList;
    opDetailList.append(new ComStructOpDetail());
    return opDetailList;
}

Q_EXPORT_PLUGIN2(OpCompanyStructPlugin, OpCompanyStructPlugin)
