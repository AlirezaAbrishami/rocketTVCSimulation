#ifndef PID_H
#define PID_H
class PID {
public:

    explicit PID(double kp, double ki, double kd, float timeStep);
    void setError(double error);
    void compute(double *currentAngle);
};

#endif // PID_H
