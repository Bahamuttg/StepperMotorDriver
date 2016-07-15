#ifndef STEPPERMOTOR_H
#define STEPPERMOTOR_H

#include<wiringPi.h>

#define CLOCKWISE 1
#define CTRCLOCKWISE -1

class StepperMotor
{
protected:
    void PerformStep(int);
private:
    unsigned int _Coil_1;
    unsigned int _Coil_2;
    unsigned int _Coil_3;
    unsigned int _Coil_4;
    unsigned int Phase;
    bool _IsHalfStep;

public:
    long Direction;
    long Position;
    bool Enabled;
    bool HoldPosition;



    StepperMotor(int Coil1, int Coil2, int Coil3, int Coil4, bool IsHalfStep);
    ~StepperMotor();

    void Rotate(int Direction, long Steps, int Delay);
};

#endif // STEPPERMOTOR_H
