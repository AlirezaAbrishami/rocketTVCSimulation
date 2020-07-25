#ifndef ROCKET_H
#define ROCKET_H

#include <QtMath>

class Rocket{
public:
    explicit Rocket(double mass, double r, double deltaT, double thrust);
    void setThrustAngle(double thrustAngle);
    void setAngle(double *currentAngle);
};

#endif // ROCKET_H
