#ifndef COMPANYSTRUCTDESIGNER_H
#define COMPANYSTRUCTDESIGNER_H

#include <QWidget>

namespace Ui {
    class CompanyStructDesigner;
}

class CompanyStructDesigner : public QWidget
{
    Q_OBJECT

public:
    explicit CompanyStructDesigner(QWidget *parent = 0);
    ~CompanyStructDesigner();

private:
    Ui::CompanyStructDesigner *ui;
};

#endif // COMPANYSTRUCTDESIGNER_H
