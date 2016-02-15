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

//Encoder Variables
double DistanceForEncoderDrive = 0;
//Gyro Variables

DriveBase::DriveBase() :
		Subsystem("DriveBase")
{
	LeftDrive1 	= new Victor(LeftMotor1);
	LeftDrive2	= new Victor(LeftMotor2);
	RightDrive1	= new Victor(RightMotor1);
	RightDrive2	= new Victor(RightMotor2);
	LeftShift 	= new DoubleSolenoid(SolenoidCAN_ID, Shift_LeftFwd, Shift_LeftRev);
	RightShift 	= new DoubleSolenoid(SolenoidCAN_ID, Shift_RightFwd, Shift_RightRev);

	//New stuff
	LeftEnc		= new Encoder(Enc_Left_A,Enc_Left_B, true, Encoder::k1X);
	RightEnc	= new Encoder(Enc_Right_A,Enc_Right_B,true,Encoder::k1X);
	//Displays the Distance for Encoder Drive for user input
	SmartDashboard::PutNumber("Distance for Encoder Drive", DistanceForEncoderDrive);
	//End New Stuff

	MainGyro	= new ADXRS450_Gyro();
	GyroScalar	= 1;
 	DS_ForDriveBase -> GetInstance();
 	
}

void DriveBase::InitDefaultCommand()
{
	SetDefaultCommand(new XboxMove());
	LeftEnc		-> Reset();
	RightEnc 	-> Reset();
	gyro        -> Calibrate();
}

void DriveBase::Drive(double LeftDriveDesired, double RightDriveDesired, double DistancePerPulseValue) //axes of joystick
  {										//									^^ This parameter will be the Encoder Conversion to Inches
										//										global variable, in RobotMap, when called

  LeftDrive1 	-> Set(LeftDriveDesired); //passes desired state to speed controllers
  LeftDrive2	-> Set(LeftDriveDesired);
  RightDrive1 	-> Set(RightDriveDesired);
  RightDrive2	-> Set(RightDriveDesired);

  //New stuff
  //Sets the ratio for pulses to inches
  LeftEnc 	-> SetDistancePerPulse(DistancePerPulseValue);
  RightEnc 	-> SetDistancePerPulse(DistancePerPulseValue);

  //Displays certain values in the encoder onto the SmartDashboard
  SmartDashboard::PutNumber("Left Encoder Raw Count Value", 	LeftEnc 	-> Get());
  SmartDashboard::PutNumber("Right Encoder Raw Count Value", 	RightEnc 	-> Get());
  SmartDashboard::PutNumber("Left Encoder Distance Traveled", 	LeftEnc 	-> GetDistance());
  SmartDashboard::PutNumber("Right Encoder Distance Traveled", 	RightEnc 	-> GetDistance());
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

  LeftDrive1		-> Set(0);
  LeftDrive2	-> Set(0);
  RightDrive1	-> Set(0);
  RightDrive2	-> Set(0);

  }

  void DriveBase::Reset()
  {
//  	LeftEnc ->Reset();
//  	RightEnc ->Reset();
  	LeftDrive1	-> Set(0);
  	LeftDrive2	-> Set(0);
  	RightDrive1	-> Set(0);
  	RightDrive2	-> Set(0);

  }
  //New stuff
  //A function to use the encoders in driving, the robot will drive in a certain direction depending on the distance left to travel
  void DriveBase::EncoderDrive(){
	  SmartDashboard::GetNumber("Distance for Encoder Drive", DistanceForEncoderDrive);
	  LeftEnc -> Reset();
	  RightEnc -> Reset();
	  while(DistanceForEncoderDrive != (LeftEnc -> GetDistance()))
		  if((DistanceForEncoderDrive - (LeftEnc -> GetDistance())) < 0)
		  {
			  LeftDrive1 -> Set(1);
			  LeftDrive2 -> Set(1);
			  RightDrive1 -> Set(-1);
			  RightDrive2 -> Set(-1);
		  }
		  else if((DistanceForEncoderDrive - (LeftEnc -> GetDistance())) > 0)
		  {
			  LeftDrive1 -> Set(-1);
			  LeftDrive2 -> Set(-1);
			  RightDrive1 -> Set(1);
			  RightDrive2 -> Set(1);
		  }
  }
  void DriveBase::EncoderReset(){
	  LeftEnc -> Reset();
	  RightEnc -> Reset();
  }

float DriveBase::ReportGyro()
{
	float Angle = (GyroScalar * MainGyro	->	GetAngle());
 	SmartDashboard::PutNumber("Gyro Angle", Angle);
	return Angle;
}
