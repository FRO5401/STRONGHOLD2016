#include "StopDriveForAutonomous.h"

StopDriveForAutonomous::StopDriveForAutonomous()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(drivebase);
}

// Called just before this Command runs the first time
void StopDriveForAutonomous::Initialize()
{
	drivebase -> Stop();
}

// Called repeatedly when this Command is scheduled to run
void StopDriveForAutonomous::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool StopDriveForAutonomous::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void StopDriveForAutonomous::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StopDriveForAutonomous::Interrupted()
{

}
