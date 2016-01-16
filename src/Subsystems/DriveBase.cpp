#include "DriveBase.h"
#include "../RobotMap.h"
//Need to check Drive() function, doesn't know which motors need to go reverse so both goes forward
//Funny stuff happening
DriveBase::DriveBase() :
		Subsystem("ExampleSubsystem")
{
	LeftDrive 	= new Victor(LeftMotor);
	RightDrive	= new Victor(RightMotor);
}

void DriveBase::InitDefaultCommand()
{
	SetDefaultCommand(new XboxMove());
}

void DriveBase::Drive(double LeftDriveDesired, double RightDriveDesired) //axes of joystick
  {

  LeftDrive 	-> Set(LeftDriveDesired); //passes desired state to speed controllers
  RightDrive 	-> Set(RightDriveDesired);

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
