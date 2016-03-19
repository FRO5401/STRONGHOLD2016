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
#include "Commands/SPTMove.h"
#include <iostream>
//Parameters for Potentiometer and the its PIDcontroller. Easier to edit if you put it here

//Multiplier to get meaningful value. A number can be put here - 0 value is horizontal from front of robot
double SPT_Range 	= -1376.15; //-1376.15
//Quote "offset added to the scaled value to control the 0 value
double SPT_Offset 	= -93.701; //(638.073 - 7.164) is old offset for Pot?SPT?Both?

double SPTMotorMin	= -1;//Min Motor speed
double SPTMotorMax	= 1;// Max motor speed
double SPTDistancePerPulseValue = -0.4327;//Angles To Pulse
float SPTMotorSpeed = .9;

float SPTDeliveryPosition 	= 55;//-34.677 from start
float SPTFeederPosition		= -21;//-112.146 from start
float SPTShootingPosition	= -50;//Position has measured 021716
double SPTMaxAngle			= 59.024; //Measured 100 degrees  021616 //normally 98
double SPTMinAngle			= -48;
double SPTPrecision = 0.5; //Set precision very high while PID and stop points are not defined //was .75
float SPTAngleTolerance = 2;

SPT::SPT() :
		Subsystem("SPT")
{
	SPTShoulderMotor = new Victor(SPTShoulderMotor_Channel);

	SPTEnc		= new Encoder(Enc_SPT_Loc_A, Enc_SPT_Loc_B, true, Encoder::k1X);
//	SPTPot = new AnalogPotentiometer(SPTPot_Channel, SPT_Range, SPT_Offset);
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
	SetDefaultCommand(new SPTMove());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.


//This function sets the shoulder motor of SPT to a certain direction between up and down
void SPT::UpAndDown(double ShoulderChangeValue, bool Override){
	if (!Override) {
	//Zero out the change if angle is at its upper limit and trying to increase
	ShoulderChangeValue = ((ShoulderChangeValue < 0) && (ReportAngle() >= SPTMaxAngle)) ? 0 : ShoulderChangeValue;
	//Zero out the change if angle is at its lower limit and trying to decrease
	ShoulderChangeValue = ((ShoulderChangeValue > 0) && (ReportAngle() <= SPTMinAngle)) ? 0 : ShoulderChangeValue;
	}
	SPTShoulderMotor -> Set(-1 * SPTPrecision * ShoulderChangeValue);

	SmartDashboard::PutNumber("SPTUpDown", ShoulderChangeValue);
	//SmartDashboard::PutNumber("SPTPot", SPTPot ->Get());
	SmartDashboard::PutNumber("SPTEnc Raw", SPTEnc -> Get());
	SmartDashboard::PutNumber("SPTEnc", SPTEnc ->GetDistance());
}

//This function sets the shoulder motor to a certain speed
//The waits a while and stops the motor at the correct angle
//The wait amount is guess and checked.

void SPT::ClearShooterPathPosition(){
	while (ReportAngle() > (SPTDeliveryPosition - 5)){
		SPTShoulderMotor -> Set(SPTMotorSpeed * SPTPrecision);
	}

	SPTShoulderMotor -> Set(0);
}

void SPT::Stop(){
	SPTShoulderMotor -> Set(0);
}

float SPT::ReportAngle(){
//	return SPTPot ->Get(); //Comment this out and uncomment the below to use encoder
	return (SPTEnc -> GetDistance() - SPT_Offset); //adjusted for offset
}

void SPT::Reset()
{
	SPTEnc	  -> Reset();
}
