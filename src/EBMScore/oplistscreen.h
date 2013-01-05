#ifndef OPLISTSCREEN_H
#define OPLISTSCREEN_H

#include <QObject>
#include <QStringList>
#include "iOpListScreen.h"

class OpListScreen : public QObject,
                        public iOpListScreen
{
    Q_OBJECT
    Q_INTERFACES(iOpListScreen)
public:
    explicit OpListScreen(QObject *parent = 0);
    virtual ~OpListScreen();

    // iOpListScreen interface
    virtual void appendOperation(QString oper);
    virtual void insertOperation(int index,QString oper);
    virtual int getOpCount();
    virtual QString getOperationAt(int index);
    virtual QStringList getOpList();
    virtual bool saveUiDetail(QDomNode& node);
    virtual bool refreshUiDetail(QDomNode& node);
    virtual void clearOpList();
    virtual void setScreenName(QString name);
    virtual QString getScreenName();
    virtual void setScreenType(QString type);
    virtual QString getScreenType();
private:
    QStringList mOpList;
    QString mScreenName;
    QString mScreenType;
};

#endif // OPLISTSCREEN_H
