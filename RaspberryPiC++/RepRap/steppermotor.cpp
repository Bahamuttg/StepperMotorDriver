#include "steppermotor.h"

StepperMotor::StepperMotor(int Coil1, int Coil2, int Coil3, int Coil4, bool HalfStep)
{
    this->_Coil_1 = Coil1;
    this->_Coil_2 = Coil2;
    this->_Coil_3 = Coil3;
    this->_Coil_4 = Coil4;
    this-> _IsHalfStep = HalfStep;

    //Init GPIO
    wiringPiSetup();
    //Setup Pin->Coil Mappings
    pinMode(_Coil_1, OUTPUT);
    pinMode(_Coil_2, OUTPUT);
    pinMode(_Coil_3, OUTPUT);
    pinMode(_Coil_4, OUTPUT);

    Phase = 0;
    Direction = CLOCKWISE;
    Position = 0;

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
    if(Enabled)
    {
        for(int i =0; i < Steps; i++)
        {
            PerformStep(Direction);
            delay(MS_Delay);
        }
    }
}

void StepperMotor::PerformStep(int Direction)
{
    int TargetPhase;

    if(Enabled)
    {
        //Record our target phase
        TargetPhase=(this->Phase + this->Direction);

        //Set coils based upon phase shift, direction,and stepping style.
        if(!_IsHalfStep)
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
        //Check if we need to reset the phase.
        if(!_IsHalfStep && TargetPhase >= 4)
            TargetPhase = 0;
        else
        {
            if (TargetPhase > 8)
                TargetPhase = 0;
        }
        //Update motor status.
        this->Phase = TargetPhase;
        this->Direction = Direction;
        this->Position += this->Direction;
    }
}

