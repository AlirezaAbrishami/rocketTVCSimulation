#include "rocket.h"
#include <QtDebug>

#define PI 3.14159265

double globalMass;
double globalR;
double globalThrust;
double acceleration;
double velocity;
double globalDeltaT;
double globalThrustAngle;


Rocket::Rocket(double mass, double r, double deltaT, double thrust) {
    globalDeltaT = deltaT;
    globalR = r;
    globalMass = mass;
    globalThrust = thrust;
}

double Rocket::getAcceleration() {
    return acceleration;
}

double Rocket::getVelocity() {
    return velocity;
}

void Rocket::setThrustAngle(double thrustAngle) {
    globalThrustAngle = thrustAngle;
}
void Rocket::setAngle(double *currentAngle) {

    double torque = globalR * globalThrust * qSin(globalThrustAngle*PI/180);
    acceleration = torque / (globalMass * globalR * globalR * 0.5);
    velocity += acceleration * globalDeltaT;
    qDebug() << acceleration;
    *currentAngle += velocity * globalDeltaT;

}


