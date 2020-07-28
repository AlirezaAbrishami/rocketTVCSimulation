#include "pid.h"

double integral;
double previousError;
double globalKp;
double globalKd;
double globalKi;
double globalError;
float globalTimeStep;

PID::PID(double kp, double ki, double kd, float timeStep) {
    globalKp = kp;
    globalKi = ki;
    globalKd = kd;
    globalTimeStep = timeStep;
}

void PID::setError(double error) {
    previousError = globalError;
    globalError = error;
}

void PID::compute(double *currentAngle) {
    if (globalError > 1) {
        integral = 0;
    }
    integral += globalError * globalTimeStep;
    double derivetive = (globalError - previousError) / globalTimeStep;
    *currentAngle =globalKi * integral + globalKp * globalError + globalKd * derivetive;
};

