#include "DriveBase.h"
#include "../RobotMap.h"
#include <Commands/XboxMove.h>
//Need to check Drive() function, doesn't know which motors need to go reverse so both goes forward
//Funny stuff happening
DriveBase::DriveBase() :
		Subsystem("DriveBase")
{
	LeftDrive1 	= new Victor(LeftMotor1);
	LeftDrive2 	= new Victor(LeftMotor2);
	LeftDrive3 	= new Victor(LeftMotor3);
	RightDrive1	= new Victor(RightMotor1);
	RightDrive2	= new Victor(RightMotor2);
	RightDrive3	= new Victor(RightMotor3);
	LeftShift = new DoubleSolenoid(pnuOff, Shift_LeftFwd, Shift_LeftRev);
	RightShift = new DoubleSolenoid(pnuOff, Shift_RightFwd, Shift_RightRev);
}

void DriveBase::InitDefaultCommand()
{
	SetDefaultCommand(new XboxMove());
}

void DriveBase::Drive(double LeftDriveDesired, double RightDriveDesired) //axes of joystick
  {

  LeftDrive1 	-> Set(LeftDriveDesired); //passes desired state to speed controllers
  LeftDrive2 	-> Set(LeftDriveDesired); //passes desired state to speed controllers
  LeftDrive3 	-> Set(LeftDriveDesired); //passes desired state to speed controllers
  RightDrive1 	-> Set(-1 * RightDriveDesired);
  RightDrive2 	-> Set(-1 * RightDriveDesired);
  RightDrive3 	-> Set(-1 * RightDriveDesired);

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

	  LeftDrive1 	-> Set(0); //passes desired state to speed controllers
	  LeftDrive2 	-> Set(0); //passes desired state to speed controllers
	  LeftDrive3 	-> Set(0); //passes desired state to speed controllers
	  RightDrive1 	-> Set(0);
	  RightDrive2 	-> Set(0);
	  RightDrive3 	-> Set(0);

  }
/*
  void DriveBase::Reset()
  {
//  	LeftEnc ->Reset();
//  	RightEnc ->Reset();
  	LeftDrive		-> Set(0);
  	RightDrive	-> Set(0);

  }
*/
