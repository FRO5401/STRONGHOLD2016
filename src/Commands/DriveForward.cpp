#include "DriveForward.h"

DriveForward::DriveForward()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(drivebase);
}

// Called just before this Command runs the first time
void DriveForward::Initialize()
{
	drivebase -> Reset(); //Can't do this in final code as gyro/timer will get reset again when we go into teleop
}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute()
{
	drivebase -> AutoDriveDistance(12.0);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished()
{
	return false;
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
