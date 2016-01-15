#include "StopDrive.h"

StopDrive::StopDrive()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(drivebase);
}

// Called just before this Command runs the first time
void StopDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void StopDrive::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool StopDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void StopDrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopDrive::Interrupted()
{

}
