/*
 * Infeeder head subsystem - "Sharp Pointy Teeth" - for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * Follow only if ye be men of valor! For the entrance to this subsystem is guarded by a creature so foul,
 * so cruel, that no programmer yet has fought with it... and lived! BONES of full fifty men lie *strewn*
 * about its lair! So! Brave knights! If you do doubt your courage or your strength, come no further,
 * for death awaits you all with nasty, big, pointy teeth...
 *
 * */


#include "SPT.h"
#include "../RobotMap.h"
#include "PIDController.h"
#include "Commands/UpAndDownInfeeder.h"
#include <iostream>
//Parameters for Potentiometer and the its PIDcontroller. Easier to edit if you put it here

//Multiplier to get meaningful value. A number can be put here - 0 value is horizontal from front of robot
double SPT_Range 	= -1376.15;
//Quote "offset added to the scaled value to control the 0 value
double SPT_Offset 	= 638.073;

double SPTMotorMin	= -1;//Min Motor speed
double SPTMotorMax	= 1;// Max motor speed
double SPTDistancePerPulseValue = .3689;
float SPTMotorSpeed = .5;

float SPTDeliveryPosition 	= -34.677;//Position has measured 022816
float SPTFeederPosition		= -112.146;//Position has measured 022816
float SPTShootingPosition	= -50;//Position has measured 021716
double SPTMaxAngle			= 80; //Measured 100 degrees  021616 //normally 98
double SPTMinAngle			= -63.082; //Measured 022816
double SPTPrecision = 0.5; //Set precision very high while PID and stop points are not defined

SPT::SPT() :
		Subsystem("SPT")
{
	SPTShoulderMotor = new Victor(SPTShoulderMotor_Channel);

	SPTEnc		= new Encoder(Enc_SPT_Loc_A, Enc_SPT_Loc_B, true, Encoder::k1X);
	SPTEnc 		-> SetDistancePerPulse(SPTDistancePerPulseValue);
	//Read Control Theory from http://www.chiefdelphi.com/media/papers/1823
	MotorOutput = 0;

//Makes the SPT subsystem constantly get the values of the global variables off the SmartDashboard
//Thus if operater makes change to values, the code will automatically input that value.
	SmartDashboard::PutNumber("SPT Range", SPT_Range);
	SmartDashboard::PutNumber("SPT Offset", SPT_Offset);
	SmartDashboard::PutNumber("SPTMotorMin", SPTMotorMin);
	SmartDashboard::PutNumber("SPTMotorMax", SPTMotorMax);
	SmartDashboard::PutNumber("SPTDeliveryPosition", SPTDeliveryPosition);
	SmartDashboard::PutNumber("SPTFeederPosition", SPTFeederPosition);
}

void SPT::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new UpAndDownInfeeder());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.


//This function sets the shoulder motor of SPT to a certain direction between up and down
void SPT::UpAndDown(double ShoulderChangeValue, bool Override){
	if (!Override) {
	//Zero out the change if angle is at its upper limit and trying to increase
	ShoulderChangeValue = ((ShoulderChangeValue < 0) && (SPTEnc -> GetDistance() >= SPTMaxAngle)) ? 0 : ShoulderChangeValue;
	//Zero out the change if angle is at its lower limit and trying to decrease
	ShoulderChangeValue = ((ShoulderChangeValue > 0) && (SPTEnc -> GetDistance() <= SPTMinAngle)) ? 0 : ShoulderChangeValue;
	}
	SPTShoulderMotor -> Set(SPTPrecision * ShoulderChangeValue); 

	SmartDashboard::PutNumber("SPTUpDown", ShoulderChangeValue);
	SmartDashboard::PutNumber("SPTEnc Raw", SPTEnc -> Get());
	SmartDashboard::PutNumber("SPTEnc", SPTEnc ->GetDistance());
}

//This function sets the shoulder motor to a certain speed
//The waits a while and stops the motor at the correct angle
//The wait amount is guess and checked.
void SPT::MoveToDeliveryPosition(){

	while (SPTEnc -> GetDistance() < SPTDeliveryPosition){
		SPTShoulderMotor -> Set(SPTMotorSpeed * SPTPrecision);
	}
}

//Same thing as MoveToDeliveryPosition but the point where it goes to is the InfeederPosition
void SPT::MoveToInfeederPosition(){
	while (SPTEnc -> GetDistance() > SPTFeederPosition){
		SPTShoulderMotor -> Set(-SPTMotorSpeed * SPTPrecision);
	}
}

void SPT::ClearShooterPathPosition(){

}

void SPT::StopForShoot(){
	SPTShoulderMotor -> Set(0);
} //TODO move  this to ClearShooterPathPosition
