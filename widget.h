#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include <QPixmap>
#include <QPainter>
#include <QtCore>
#include <QtConcurrent/QtConcurrent>
#include <QtDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void draw(double angle);
    void cycle();
    Ui::Widget* ui;

private slots:
    void on_pushButton_clicked();


};
#endif // WIDGET_H
