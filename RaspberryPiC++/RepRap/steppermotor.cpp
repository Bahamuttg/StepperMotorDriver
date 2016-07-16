#include "steppermotor.h"
#include <wiringPi.h>

StepperMotor::StepperMotor(int Coil1, int Coil2, int Coil3, int Coil4, bool IsHalfStep)
{
    this->_Coil_1 = Coil1;
    this->_Coil_2 = Coil2;
    this->_Coil_3 = Coil3;
    this->_Coil_4 = Coil4;
    this->_IsHalfStep = IsHalfStep;


    //Setup Pin->Coil Mappings
    pinMode(_Coil_1, OUTPUT);
    pinMode(_Coil_2, OUTPUT);
    pinMode(_Coil_3, OUTPUT);
    pinMode(_Coil_4, OUTPUT);

    Phase = 0;
    Direction = CLOCKWISE;
    Position = 0;
    HoldPosition = true;
}

StepperMotor::~StepperMotor()
{
    digitalWrite(_Coil_1, LOW);
    digitalWrite(_Coil_2, LOW);
    digitalWrite(_Coil_3, LOW);
    digitalWrite(_Coil_4, LOW);
}

void StepperMotor::Rotate(int Direction, long Steps, int MS_Delay)
{
    if (Enabled)
    {
        for (int i = 0; i < Steps; i++)
        {
            PerformStep(Direction);
            delay(MS_Delay);
        }
    }
}

void StepperMotor::PerformStep(int Direction)
{
    //const unsigned int NotGateFullStep[4][2] = {{1,0},{0,0},{0,1},{1,1}};
    //full step sequence. maximum torque
    const unsigned int FullStep[4][4] = { {1,1,0,0},{0,1,1,0},{0,0,1,1},{1,0,0,1} };
    //half-step sequence. double resolution. But the torque of the stepper motor is not constant
    const unsigned int HalfStep[8][4] = { {1,0,0,0},{1,1,0,0},{0,1,0,0},{0,1,1,0},{0,0,1,0},{0,0,1,1},{0,0,0,1},{1,0,0,1} };
    int TargetPhase;

    if (Enabled)
    {
        this->Direction = Direction;

        //Record our target phase
        TargetPhase = (this->Phase + this->Direction);

        //Check if we need to reset the phase.
        if (!_IsHalfStep)
        {
            if(this->Direction == CLOCKWISE && TargetPhase > 3)
            {
                TargetPhase = 0;
            }
            else if(this->Direction == CTRCLOCKWISE && TargetPhase < 0)
            {
                TargetPhase = 3;
            }
        }
        else
        {
            if(this->Direction == CLOCKWISE && TargetPhase > 7)
            {
                TargetPhase = 0;
            }
            else if(this->Direction == CTRCLOCKWISE && TargetPhase < 0)
            {
                TargetPhase = 7;
            }
        }

        //Set coils based upon phase shift, direction,and stepping style.
        if (!_IsHalfStep)
        {
            digitalWrite(_Coil_1, FullStep[TargetPhase][0]);
            digitalWrite(_Coil_2, FullStep[TargetPhase][1]);
            digitalWrite(_Coil_3, FullStep[TargetPhase][2]);
            digitalWrite(_Coil_4, FullStep[TargetPhase][3]);
        }
        else
        {
            digitalWrite(_Coil_1, HalfStep[TargetPhase][0]);
            digitalWrite(_Coil_2, HalfStep[TargetPhase][1]);
            digitalWrite(_Coil_3, HalfStep[TargetPhase][2]);
            digitalWrite(_Coil_4, HalfStep[TargetPhase][3]);
        }

        //Update motor status.
        this->Phase = TargetPhase;
        this->Position += this->Direction;
    }
    //If we're not holding the motor position let's release it.
    if (!HoldPosition)
    {
        digitalWrite(_Coil_1, LOW);
        digitalWrite(_Coil_2, LOW);
        digitalWrite(_Coil_3, LOW);
        digitalWrite(_Coil_4, LOW);
    }
}


