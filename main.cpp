#include "widget.h"

#include <QApplication>

#include "ElaApplication.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ElaApplication::getInstance()->init();

    Widget w;
    w.show();
    return a.exec();
}
