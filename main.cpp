#include "mainwindow.h"

#include <QApplication>
#include <QPaintEvent>
#include <QPixmap>
#include <QPainter>
#include "widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    Widget *widget = new Widget();
    widget->show();
    printf("hello");
    return a.exec();
}
