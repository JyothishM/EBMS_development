#ifndef IEBMS_H
#define IEBMS_H

#include <QObject>
#include <QStringList>
#include <QList>


class iOperationDetail;
class iOpListScreen;

class iEBMS
{
public:
    virtual ~iEBMS() {}
    //settings
    virtual void setOpPluginPaths(QStringList paths)=0;
    virtual QStringList getOpPluginPaths()=0;
    virtual void setConigFile(QString filename)=0;
    virtual QString getConigFile()=0;
    virtual void setUiXmlFile(QString filename)=0;
    virtual QString getUiXmlFile()=0;

    // save refresh functions.
    virtual bool refreshUiDetail()=0;
    virtual bool saveUiDetail()=0;
    virtual void refreshOpDetails()=0;

    // operations
    virtual QStringList getOperationNames()=0;
    virtual QList<iOperationDetail*> getOperationDetailList()=0;
    virtual iOperationDetail* getOperationDetail(QString name)=0;

    // operation list screens
    virtual QStringList getOpListScreenNames()=0;
    virtual QList<iOpListScreen*> getOpListScreens()=0;
    virtual iOpListScreen* getOpListScreen(QString name)=0;
protected:
    virtual iOperationDetail* createOperationDetail(QString type)=0;
    virtual iOpListScreen* createOpListScreen(QString type)=0;
};

Q_DECLARE_INTERFACE(iEBMS,
                     "com.vismayainfotech.iEBMS/1.0")


#endif // IEBMS_H
