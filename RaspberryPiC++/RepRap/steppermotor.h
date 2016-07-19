#ifndef STEPPERMOTOR_H
#define STEPPERMOTOR_H

#include<wiringPi.h>

namespace Stepper
{
    class StepperMotor;
}
class StepperMotor
{
private:
    unsigned int _Coil_1;
    unsigned int _Coil_2;
    unsigned int _Coil_3;
    unsigned int _Coil_4;
    unsigned int Phase;
    bool _IsHalfStep;

public:
    enum MotorDirection
    {
        CLOCKWISE = 1,
        CTRCLOCKWISE = -1
    };

    MotorDirection Direction;
    long Position;
    bool Enabled;
    bool HoldPosition;

    explicit StepperMotor(int Coil1, int Coil2, int Coil3, int Coil4, bool IsHalfStep);
    ~StepperMotor();

    void Rotate(MotorDirection Direction, long Steps, int Delay);


protected:
    void PerformStep(MotorDirection);
};

#endif // STEPPERMOTOR_H
