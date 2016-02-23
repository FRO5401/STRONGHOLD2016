#include "DriveForward.h"

DriveForward::DriveForward()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(drivebase);
	distance = 0; //might be able to be done in .h
	SmartDashboard::PutNumber("Desired AutoDrive Distance(ft)", distance);
	distance = SmartDashboard::GetNumber("Desired AutoDrive Distance(ft)", distance);

}

// Called just before this Command runs the first time
void DriveForward::Initialize()
{
	drivebase -> Reset(); //Can't do this in final code as gyro/timer will get reset again when we go into teleop
}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute()
{
	distance = SmartDashboard::GetNumber("Desired AutoDrive Distance(ft)", distance);
	drivebase -> AutoDriveDistance(distance);
	distance = -1;
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished()
{
	if (distance == -1){
		return true;
	} else {
		return false;
	}
}

// Called once after isFinished returns true
void DriveForward::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForward::Interrupted()
{

}
