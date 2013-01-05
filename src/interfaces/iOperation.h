#ifndef IOPERATION_H
#define IOPERATION_H

#include <QString>
#include <QObject>

class iOperation
{
public:
    virtual ~iOperation() {}
};

Q_DECLARE_INTERFACE(iOperation,
                     "com.vismayainfotech.iOperation/1.0")

#endif // IOPERATION_H
