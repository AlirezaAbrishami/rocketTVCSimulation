#include "widget.h"
#include "ui_Widget.h"
#include "pid.h"
#include "rocket.h"

float timeStep = 0.001;
int simTime = 8000;
double initialAngle = 45.0;
int timer = 0;
double mass = 1.3;   //kg
double thrust = 21;    //Newtons
double currentRocketAngle = initialAngle;
double correctAngle = 0;
double r = 0.3; //Meters
double thrustAngle;

//PID constants
double kp = 4;
double ki = 0.01;
double kd = 3;

bool loop = true;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    draw(0);
//    ui->label->setPixmap(QPixmap(":/Resources/image.png"));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::draw(double angle) {
    QApplication::processEvents();
    QPixmap ship(":/new/prefix1/rocket");
    QSize qsize = ship.size();
    qsize.setWidth(1200);
    QPixmap rotate(qsize);
    QPainter p(&rotate);
    p.setRenderHint(QPainter::Antialiasing);
    p.setRenderHint(QPainter::SmoothPixmapTransform);
    p.setRenderHint(QPainter::HighQualityAntialiasing);
//    qDebug() << "width: " << rotate.size().width();
//    qDebug() << "height: " << rotate.size().width();
    p.translate((119 / 2) + 0, rotate.size().height() / 2);
    p.rotate(angle);
    p.translate((-119 / 2) + 0, -rotate.size().height() / 2);
    p.drawPixmap(0, 0, ship);
    p.end();
    ui->label->setPixmap(rotate);

}

void delay() {
    int ms = 1;
    struct timespec ts = { ms / 1000, (ms % 1000) * 1000 * 1000 };
    nanosleep(&ts, NULL);
}

void Widget::cycle() {
    Rocket rocket(mass, r, timeStep, thrust);
    PID pid(kp, ki, kd, timeStep);
    //change the path
    QString filename = "/home/alireza/qtprojects/simulation/data/thrustAngleData.txt";
    QFile file(filename);
    file.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream stream(&file);

    //change the path
    QString filename1 = "/home/alireza/qtprojects/simulation/data/rocketAngleData.txt";
    QFile file1(filename1);
    file1.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream stream1(&file1);

    //change the path
    QString filename2 = "/home/alireza/qtprojects/simulation/data/rocketAccelerationData.txt";
    QFile file2(filename2);
    file2.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream stream2(&file2);

    //change the path
    QString filename3 = "/home/alireza/qtprojects/simulation/data/rocketVelocityData.txt";
    QFile file3(filename3);
    file3.open(QIODevice::ReadWrite | QIODevice::Append);
    QTextStream stream3(&file3);

    for (int i = 0; i <= simTime; i++) {
        double error = correctAngle - currentRocketAngle;
        pid.setError(error);
        pid.compute(&thrustAngle);
//        qDebug() << thrustAngle;
        if (thrustAngle > 10)
            thrustAngle = 10;
        if (thrustAngle < -10)
            thrustAngle = -10;
        rocket.setThrustAngle(thrustAngle);
        rocket.setAngle(&currentRocketAngle);
        delay();    //use something else if you're not using linux
        stream << thrustAngle << ",";
        stream1 << currentRocketAngle << ",";
        stream2 << rocket.getAcceleration() << ",";
        stream3 << rocket.getVelocity() << ",";
    }
    loop = false;
    qDebug() << currentRocketAngle;
}



void Widget::on_pushButton_clicked() {
    QFuture <void> future = QtConcurrent::run(this, &Widget::cycle);
    while (loop) {
        draw(currentRocketAngle);
    }
}
