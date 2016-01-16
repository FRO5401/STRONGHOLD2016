#include "XboxDrivingSkid.h"

XboxDrivingSkid::XboxDrivingSkid()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(drivebase);
}

// Called just before this Command runs the first time
void XboxDrivingSkid::Initialize()
{
	drivebase	-> Reset();
}

// Called repeatedly when this Command is scheduled to run
void XboxDrivingSkid::Execute()
{
	double LeftMove = oi -> ReadXboxLeftAxisY();
	double RightMove = oi -> ReadXboxRightAxisY();

	//The SmartDashboard class allows the programmer to tinker with the SmartDashboard on the driver station
	//The PutNumber function has the parameters (string, number)
	//The string will be permanently displayed
	//Number will also be displayed but may change over time
	SmartDashboard::PutNumber("Left Motor", LeftMove);
	SmartDashboard::PutNumber("Right Motor", RightMove);


	if(LeftMove < 0 && RightMove < 0)
	{
		//Move Forward
		drivebase -> Drive(LeftMove, RightMove, MinSensitivityThreshold, MaxSensitivityThreshold);
	}else if(LeftMove > 0 && RightMove > 0)
	{
		//Move Backward
		drivebase -> Drive(LeftMove, RightMove, MinSensitivityThreshold, MaxSensitivityThreshold);
	}else if(LeftMove < 0 && RightMove > 0)
	{
		//Turn Right
		drivebase -> Drive(LeftMove, RightMove, MinSensitivityThreshold, MaxSensitivityThreshold);
	}else if(LeftMove > 0 && RightMove < 0)
	{
		//Turn Left
		drivebase -> Drive(LeftMove, RightMove, MinSensitivityThreshold, MaxSensitivityThreshold);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool XboxDrivingSkid::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void XboxDrivingSkid::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void XboxDrivingSkid::Interrupted()
{

}
