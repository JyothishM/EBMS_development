#include "ebms.h"
#include "iOperation.h"
#include "iOperationDetail.h"
#include "iOpListScreen.h"
#include "ebms_common.h"
#include "logger.h"
#include "oplistscreen.h"
#include "iOperationPlugin.h"
#include <QDate>
#include <QDomDocument>
#include <QDomNode>
#include <QDomElement>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QPluginLoader>
#include <QDir>


EBMS::EBMS(QObject* parent)
    : QObject(parent)
{
    initEBMS();
    refreshUiDetail();
}

EBMS::~EBMS()
{

}

void EBMS::setOpPluginPaths(QStringList paths)
{
    mOpPluginPaths = paths;
}

QStringList EBMS::getOpPluginPaths()
{
    return mOpPluginPaths;
}

void EBMS::setConigFile(QString filename)
{
    mConfigFile = filename;
}

QString EBMS::getConigFile()
{
    return mConfigFile;
}

void EBMS::setUiXmlFile(QString filename)
{
    mUiXmlFile = filename;
}

QString EBMS::getUiXmlFile()
{
    return mUiXmlFile;
}

bool EBMS::refreshUiDetail()
{
    bool succes=false;
    clearUiDetail();
    QDomDocument doc(UIDETAIL_DOCNAME);
    if(readXmlFile(mUiXmlFile,doc))
    {
        readOpDetail(doc);
        succes = true;
    }
    return succes;
}

bool EBMS::saveUiDetail()
{
    bool succes=false;
    QDomDocument doc(UIDETAIL_DOCNAME);
    writeOpDetail(doc);
    if(writeXmlFile(mUiXmlFile,doc))
    {
        succes = true;
    }
    return succes;
}


void EBMS::refreshOpDetails()
{
    // clearing previos
    qDeleteAll(mOpDetailHash.values());
    mOpDetailHash.clear();

    QList<iOperationDetail*> opDetails = loadOpDetails(mOpPluginPaths);
    foreach(iOperationDetail* detail,opDetails)
    {
        if(detail)
        {
            QString name = detail->getOpName();
            if(!mOpDetailHash.value(name,0))
            {
                mOpDetailHash.insert(name,detail);
                qDebug() << QString("operation :%0 added.").arg(name);
                Logger::curLog(QString("operation :%0 added.").arg(name));
            }
            else
            {
                qDebug() << QString("operation :%0 already exists, deleting additional detail obj.").arg(name);
                Logger::curLog(QString("operation :%0 already exists, deleting additional detail obj.").arg(name));
                delete detail;   //   already same operation name is available delete this
            }
        }
    }
}

QStringList EBMS::getOperationNames()
{
    return mOpDetailHash.keys();
}

QList<iOperationDetail*> EBMS::getOperationDetailList()
{
    return mOpDetailHash.values();
}

iOperationDetail* EBMS::getOperationDetail(QString name)
{
    return mOpDetailHash.value(name,0);
}

QStringList EBMS::getOpListScreenNames()
{
    return mOpListScrOHash.orderedKeys();
}

QList<iOpListScreen*> EBMS::getOpListScreens()
{
    return mOpListScrOHash.orderedValues();
}

iOpListScreen* EBMS::getOpListScreen(QString name)
{
    return mOpListScrOHash.value(name,0);
}

/////////////////protected///////////////////////////////////
iOperationDetail* EBMS::createOperationDetail(QString type)   // not implimented.
{
    return 0;
}

iOpListScreen* EBMS::createOpListScreen(QString type)
{
    OpListScreen* optscreen = new OpListScreen(this);
    optscreen->setScreenType(type);
    return optscreen;
}

/////////////////private/////////////////////////////////////
void EBMS::initEBMS()
{
    QString logFileName = QString(ROOTFOLDER)
                          .append(LOGFOLDER)
                          .append(QDate::currentDate().toString("MM_dd_yyyy.log"));

    mConfigFile = QString(ROOTFOLDER)
                  .append(SETTINGS_FOLDER)
                  .append(CONFIGFILE);

    mUiXmlFile = QString(ROOTFOLDER)
                  .append(SETTINGS_FOLDER)
                  .append(UIDETAIL_XMLFILE);

    Logger* logger = new Logger(logFileName);
    Logger::SetCurLogger(logger);
}

bool EBMS::readXmlFile(QString filename,QDomDocument& doc)
{
    bool succes=false;
    QFile file(filename);
    if (file.open(QIODevice::ReadOnly))
    {
        if (doc.setContent(&file))
        {
            succes = true;
        }
        file.close();
    }
    return succes;
}

void EBMS::readOpDetail(QDomDocument& doc)
{
    QDomElement docElem = doc.documentElement();
    if(docElem.tagName() != TAGNAME_OPLISTSCREENLIST)
        return;

    QDomNodeList OpScreenList = docElem.elementsByTagName(TAGNAME_OPLISTSCREEN);
    int count = OpScreenList.count();
    for(int i=0; i<count; i++)
    {
        QDomNode n = OpScreenList.at(i);
        QDomElement e = n.toElement();
        if(!e.isNull())
        {
            QString name = e.attribute(ATTRB_NAME);
            QString type = e.attribute(ATTRB_TYPE);

            if(!name.isEmpty())
            {
                iOpListScreen* opListScreen = createOpListScreen(type);
                opListScreen->setScreenName(name);
                if(opListScreen)
                {
                    iOpListScreen* prevOpListScreen = mOpListScrOHash.value(name,0);
                    if(prevOpListScreen)
                    {
                        delete prevOpListScreen;
                    }
                    mOpListScrOHash.append(name,opListScreen);
                    opListScreen->refreshUiDetail(e);
                }
            }
        }
    }
}

void EBMS::writeOpDetail(QDomDocument& doc)
{
    QDomElement elm = doc.createElement(TAGNAME_OPLISTSCREENLIST);
    foreach(iOpListScreen* opListScreen,mOpListScrOHash.orderedValues())
    {
        if(opListScreen)
        {
            qDebug() << opListScreen->getScreenName();
            opListScreen->saveUiDetail(elm);
        }
    }

    doc.appendChild(elm);
 }

bool EBMS::writeXmlFile(QString filename,QDomDocument& doc)
{
    bool succes=false;
    QFile file(filename);
    if (file.open(QIODevice::WriteOnly))
    {
        QTextStream out(&file);
        out << doc.toString();
        succes = true;
        file.close();
    }
    return succes;
}

void EBMS::clearUiDetail()
{
    qDeleteAll(mOpListScrOHash.values());
    mOpListScrOHash.clear();
}

QObject* EBMS::createPluginObj(QString filename)
{
    QObject* obj=0;
    QPluginLoader loader(filename,this);
    if(loader.load())
    {
        obj = loader.instance();
        qDebug() << filename << " loaded.";
        Logger::curLog(filename+ " loaded.");
        //loader.unload();
    }
    else
    {
        qDebug() << "failed to load " << filename;
        Logger::curLog(QString("failed to load '%0', error: %1").arg(filename).arg(loader.errorString()),
                       Logger::ERROR);
    }

    return obj;
}

QList<iOperationDetail*> EBMS::loadOpDetails(QStringList& paths)
{
    QList<iOperationDetail*> detailList;
    foreach(QString path,paths)
    {
        QDir dir(path);
        QStringList filters;
        #ifdef Q_OS_WIN32
                filters << "*.dll";
        #else //Q_OS_LINUX
                filters << "*.so";
        //#else
        //        filters << "*";
        #endif

        QStringList files = dir.entryList(filters);

        foreach(QString file,files)
        {
            QObject* obj = createPluginObj(dir.filePath(file));
            if(obj)
            {
                iOperationPlugin* plugin = dynamic_cast<iOperationPlugin*>(obj);
                if(plugin)
                {
                    detailList.append(plugin->createOpDetails());

                    qDebug() << "plugin loaded " << plugin->getPluginName();
                    Logger::curLog("plugin loaded " + plugin->getPluginName());
                }
            }
        }

    }
    return detailList;
}

