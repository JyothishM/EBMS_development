#include "companystructdesigner.h"
#include "ui_companystructdesigner.h"

CompanyStructDesigner::CompanyStructDesigner(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CompanyStructDesigner)
{
    ui->setupUi(this);
}

CompanyStructDesigner::~CompanyStructDesigner()
{
    delete ui;
}
