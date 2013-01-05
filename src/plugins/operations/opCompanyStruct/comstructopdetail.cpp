#include "comstructopdetail.h"
#include "companystructdesigner.h"
#include <QWidget>
#include <QIcon>

ComStructOpDetail::ComStructOpDetail()
{
}

ComStructOpDetail::~ComStructOpDetail()
{

}

QString ComStructOpDetail::getOpName()
{
    return "DefineStructure";
}

QString ComStructOpDetail::getOpVersion()
{
    return "1.0.0";
}

QIcon ComStructOpDetail::getIcon()
{
    return QIcon(":/icon/resources/icons/organizational_structure.jpg");
}

QWidget* ComStructOpDetail::createScreen(QString /*type*/)
{
    return new CompanyStructDesigner();
}
