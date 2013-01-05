#include <QtGui/QApplication>
#include "ebmsui.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EBMSui w;
    w.show();
    return a.exec();
}
