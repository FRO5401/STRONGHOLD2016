#include "AutoDriveCommand.h"

AutoDriveCommand::AutoDriveCommand(float DistanceInput)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivebase);
	DistanceToDrive = DistanceInput;
}

// Called just before this Command runs the first time
void AutoDriveCommand::Initialize()
{
	drivebase	-> 	AutoDriveDistance(DistanceToDrive);
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveCommand::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveCommand::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void AutoDriveCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveCommand::Interrupted()
{

}

