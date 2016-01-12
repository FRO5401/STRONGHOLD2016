#include "Drivebase.h"
#include "../RobotMap.h"
//Need to check Drive() function, doesn't know which motors need to go reverse so both goes forward
Drivebase::Drivebase() :
		Subsystem("ExampleSubsystem")
{
	LeftDrive 	= new Victor(LeftMotor);
	RightDrive	= new Victor(RightMotor);
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

void Drivebase::Stop()
{
	LeftDrive	->Set(0);
	RightDrive	->Set(0);
}
