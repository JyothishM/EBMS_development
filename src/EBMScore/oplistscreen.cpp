#include "oplistscreen.h"
#include "iEBMS.h"
#include "iOperationDetail.h"
#include "ebms_common.h"
#include <QDomNode>
#include <QDebug>

OpListScreen::OpListScreen(QObject *parent) :
    QObject(parent)
{
    mScreenType = "default";
}

OpListScreen::~OpListScreen()
{
}

void OpListScreen::appendOperation(QString oper)
{
    mOpList.append(oper);
}

void OpListScreen::insertOperation(int index,QString oper)
{
    mOpList.insert(index,oper);
}

int OpListScreen::getOpCount()
{
    return mOpList.count();
}

QString OpListScreen::getOperationAt(int index)
{
    if(index < mOpList.count())
        return mOpList.at(index);

    return 0;
}

QStringList OpListScreen::getOpList()
{
    return mOpList;
}

bool OpListScreen::saveUiDetail(QDomNode& node)
{
    bool succes=false;
    QDomDocument doc = node.ownerDocument();
    QDomElement elm = doc.createElement(TAGNAME_OPLISTSCREEN);
    elm.setAttribute(ATTRB_NAME,mScreenName);
    elm.setAttribute(ATTRB_TYPE,mScreenType);
    foreach(QString opName,mOpList)
    {
        QDomElement opElm = doc.createElement(TAGNAME_OPERATION);
        opElm.setAttribute(ATTRB_NAME,opName);
        elm.appendChild(opElm);
    }
    node.appendChild(elm);
    succes = true;
    return succes;
}

bool OpListScreen::refreshUiDetail(QDomNode& node)
{
    bool succes=false;
    clearOpList();
    QDomElement elm = node.toElement();
    if(!elm.isNull())
    {
        if(elm.tagName() == TAGNAME_OPLISTSCREEN)
        {
            //looking in child items.
            QDomNodeList opList = elm.elementsByTagName(TAGNAME_OPERATION);
            int count = opList.count();
            for(int i=0; i<count; i++)
            {
                QDomElement opElm = opList.at(i).toElement();
                if(!opElm.isNull())
                {
                    QString opElmName = opElm.attribute(ATTRB_NAME);
                    if(!opElmName.isEmpty())
                        appendOperation(opElmName);
                }
            }
            succes=true;
        }
    }
    return succes;
}
void OpListScreen::clearOpList()
{
    mOpList.clear();
}

void OpListScreen::setScreenName(QString name)
{
    mScreenName = name;
}

QString OpListScreen::getScreenName()
{
    return mScreenName;
}

void OpListScreen::setScreenType(QString type)
{
    mScreenType = type;
}

QString OpListScreen::getScreenType()
{
    return mScreenType;
}
