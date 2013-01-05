#ifndef EBMS_H
#define EBMS_H

#include "EBMScore_global.h"
#include "iEBMS.h"
#include "orderedhash.h"
#include <QObject>
#include <QHash>

class QDomDocument;
class QDomNode;
class QDomElement;

class EBMSCORESHARED_EXPORT EBMS : public QObject,
                                   public iEBMS
{
    Q_INTERFACES(iEBMS)
public:
    EBMS(QObject* parent=0);
    virtual ~EBMS();

    // iEBMS interface
    virtual void setOpPluginPaths(QStringList paths);
    virtual QStringList getOpPluginPaths();
    virtual void setConigFile(QString filename);
    virtual QString getConigFile();
    virtual void setUiXmlFile(QString filename);
    virtual QString getUiXmlFile();
    virtual bool refreshUiDetail();
    virtual bool saveUiDetail();
    virtual void refreshOpDetails();
    virtual QStringList getOperationNames();
    virtual QList<iOperationDetail*> getOperationDetailList();
    virtual iOperationDetail* getOperationDetail(QString name);
    virtual QStringList getOpListScreenNames();
    virtual QList<iOpListScreen*> getOpListScreens();
    virtual iOpListScreen* getOpListScreen(QString name);
protected:
    virtual iOperationDetail* createOperationDetail(QString type="default");
    virtual iOpListScreen* createOpListScreen(QString type="default");
private:
    void initEBMS();
    bool readXmlFile(QString filename,QDomDocument& doc);
    void readOpDetail(QDomDocument& doc);
    void writeOpDetail(QDomDocument& doc);
    bool writeXmlFile(QString filename,QDomDocument& doc);
    void clearUiDetail();
    QObject* createPluginObj(QString filename);
    QList<iOperationDetail*> loadOpDetails(QStringList& paths);


    QString mConfigFile;
    QString mUiXmlFile;
    QStringList mOpPluginPaths;
    QHash<QString,iOperationDetail*> mOpDetailHash;
    OrderedHash<QString,iOpListScreen*> mOpListScrOHash;
};

#endif // EBMS_H
