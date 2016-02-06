/*
 * Drive Base subsystem for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * Subsystem's got two empty halves of coconut and is bangin' 'em together.
 */

#include "DriveBase.h"
#include "../RobotMap.h"
#include <Commands/XboxMove.h>
//Need to check Drive() function, doesn't know which motors need to go reverse so both goes forward
//Funny stuff happening
DriveBase::DriveBase() :
		Subsystem("DriveBase")
{
	LeftDrive 	= new Victor(LeftMotor);
	RightDrive	= new Victor(RightMotor);
	LeftShift 	= new DoubleSolenoid(SolenoidCAN_ID, Shift_LeftFwd, Shift_LeftRev);
	RightShift 	= new DoubleSolenoid(SolenoidCAN_ID, Shift_RightFwd, Shift_RightRev);
	LeftEnc		= new Encoder(Enc_Left_A,Enc_Left_B, true, Encoder::k1X);
	RightEnc	= new Encoder(Enc_Right_A,Enc_Right_B,true,Encoder::k1X);
}

void DriveBase::InitDefaultCommand()
{
	SetDefaultCommand(new XboxMove());
	LeftEnc		-> Reset();
	RightEnc 	-> Reset():
}

void DriveBase::Drive(double LeftDriveDesired, double RightDriveDesired, double DistancePerPulseValue) //axes of joystick
  {										//									^^ This parameter will be the Encoder Conversion to Inches
										//										global variable, in RobotMap, when called

  LeftDrive 	-> Set(LeftDriveDesired); //passes desired state to speed controllers
  RightDrive 	-> Set(RightDriveDesired);

  LeftEnc 	-> SetDistancePerPulse(DistancePerPulseValue);
  RightEnc 	-> SetDistancePerPulse(DistancePerPulseValue);

  SmartDashboard::PutNumber("Left Encoder Raw Count Value", LeftEnc -> Get());
  SmartDashboard::PutNumber("Right Encoder Raw Count Value", RightEnc -> Get());
  SmartDashboard::PutNumber("Left Encoder Distance Traveled", LeftEnc -> GetDistance());
  SmartDashboard::PutNumber("Right Encoder Distance Traveled", RightEnc -> GetDistance());

  }
void DriveBase::ShiftLow()
{
	LeftShift  ->	Set(DoubleSolenoid::Value::kForward);
	RightShift ->	Set(DoubleSolenoid::Value::kForward);
}

void DriveBase::ShiftHigh()
{
	LeftShift  ->	Set(DoubleSolenoid::Value::kReverse);
	RightShift ->	Set(DoubleSolenoid::Value::kReverse);
}

 void DriveBase::Stop()
  {

  LeftDrive		-> Set(0);
  RightDrive	-> Set(0);

  }

  void DriveBase::Reset()
  {
//  	LeftEnc ->Reset();
//  	RightEnc ->Reset();
  	LeftDrive		-> Set(0);
  	RightDrive	-> Set(0);

  }
