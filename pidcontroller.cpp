#include <iostream>
#include "pid.hpp"
using namespace std;

class PID {
    public:
        PID (double dt, double max, double min, double Kp,double Kd, double Ki);
        double calculate (double desiredpostion, double currentposition);
    private:
        double _dt;
        double _max;
        double _min;
        double _Kp;
        double _Kd;
        double _Ki;
        double _pre_error;
        double _integral;
};

PID::PID (double dt, double max, double min, double Kp, double Kd, double Ki ) {
    _dt = dt;
    _max = max;
    _min = min;
    _Kp = Kp;
    _Kd = Kd;
    _Ki = Ki;
    _pre_error = 0;
    _integral = 0;
}

double PID::calculate (double desiredposition, double currentposition) {
    double error = desiredposition - currentposition;
    double Pout = _Kp * error;
    _integral += error * _dt;
    double Iout = _Ki * _integral;
    double derivative = (error - _pre_error) / _dt;
    double Dout = _Kd * derivative;
    double output = Pout + Iout + Dout;
    if( output > _max )
        output = _max;
    else if( output < _min )
        output = _min;
    _pre_error = error;
    return output;
}

void stabilize () {
    double current_height = getHeight ();
    double desired_height;
}

int main() {
    double desiredHeight;
    cout << "Desired Height: ";
    cin >> desiredHeight;
    double currentHeight = getHeight ();

    PID pid = PID(0.4, 200, -200, 0.3, 0.05, 0.1);

    for (int i = 0; i < 100; i++) {
        double inc = pid.calculate(desiredHeight, currentHeight);
        printf("val:% 7.3f inc:% 7.3f\n", currentHeight, inc);
        currentHeight += inc;
    }
    return 0;
}
