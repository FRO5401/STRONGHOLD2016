#include "Drivebase.h"
#include "../RobotMap.h"
//Need to check Drive() function, doesn't know which motors need to go reverse so both goes forward
Drivebase::Drivebase() :
		Subsystem("ExampleSubsystem")
{
	LeftDrive 	= new Victor(LeftMotor);
	RightDrive	= new Victor(RightMotor);
	RightEncoder	= new Encoder(RightEncoder_A, RightEncoder_B, false, Encoder::k1X);
	LeftEncoder		= new Encoder(LeftEncoder_A, LeftEncoder_B, true, Encoder::k1X);
}

void Drivebase::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

//Desired speeds of left and right motors will pass through in commands
void Drivebase::Drive(double LeftDesired, double RightDesired, double MinSensitivity, double MaxSensitivity)
{
	SmartDashboard::PutNumber("Left Drive Count", LeftEncoder 		-> Get());
	SmartDashboard::PutNumber("Right Drive Count", RightEncoder 	-> Get());
	SmartDashboard::PutNumber("Left Drive Distance", LeftEncoder 	-> GetDistance());
	SmartDashboard::PutNumber("Right Drive Distance", RightEncoder 	-> GetDistance());

	//Logic for Left Motors
	//Makes the left motor runs only if the joystick is pushed forward enough
	//But puts a max speed on the robot, so it doesn't go too fast
	//absolute value is used because the joystick might be pushed back to go backward
	if(abs(LeftDesired)>MinSensitivity)
	{
		if(abs(LeftDesired)>MaxSensitivity)
		{
			//Sets motor to desired speed
			LeftDrive 	->Set(LeftDesired*MaxSensitivity);
		}else
		{
			LeftDrive	->Set(LeftDesired);
		}
	}
	if(abs(RightDesired)>MinSensitivity)
	{
		if(abs(RightDesired)>MaxSensitivity)
		{
				//Sets motor to desired speed
				RightDrive 	->Set(RightDesired*MaxSensitivity);
		}else
		{
				RightDrive	->Set(RightDesired);
		}
	}
}

//Function used in command when you want the robot to stop
void Drivebase::Stop()
{
	LeftDrive	->Set(0);
	RightDrive	->Set(0);
}

//Program to reset the Drivebase parts such that the robot is still, and encoders reset
void Drivebase::Reset()
{
	LeftEncoder ->Reset();
	RightEncoder ->Reset();
	LeftDrive	-> Set(0);
	RightDrive	-> Set(0);

}
