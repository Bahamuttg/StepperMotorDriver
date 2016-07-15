#ifndef STEPPERMOTOR_H
#define STEPPERMOTOR_H

#include<wiringPi.h>

#define CLOCKWISE 1;
#define CTRCLOCKWISE -1;

class StepperMotor
{
private:
    unsigned int _Coil_1;
    unsigned int _Coil_2;
    unsigned int _Coil_3;
    unsigned int _Coil_4;
    unsigned int Phase;
    bool _IsHalfStep;

    void PerformStep(int, bool);
public:
    //full step sequence. maximum torque
    static const unsigned int FullStep[4][4];
    //half-step sequence. double resolution. But the torque of the stepper motor is not constant
    static const unsigned int HalfStep [8][4];

    long Direction;
    long Position;
    bool Enabled;
    bool HoldPosition;

    StepperMotor(int Coil1, int Coil2, int Coil3, int Coil4, bool HalfStep);
    ~StepperMotor();

    void Rotate(int Direction, long Steps, int Delay);


};

const unsigned int StepperMotor::FullStep[4][4] = {{1,1,0,0},{0,1,1,0},{0,0,1,1},{1,0,0,1}};
const unsigned int StepperMotor::HalfStep[8][4] = {{1,0,0,0},{1,1,0,0},{0,1,0,0},{0,1,1,0},{0,0,1,0},{0,0,1,1},{0,0,0,1},{1,0,0,1}};

#endif // STEPPERMOTOR_H
