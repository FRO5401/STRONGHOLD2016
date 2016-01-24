#include "ShiftScaleToDrive.h"

ShiftScaleToDrive::ShiftScaleToDrive()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(scale);
}

// Called just before this Command runs the first time
void ShiftScaleToDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ShiftScaleToDrive::Execute()
{
	scale	->	DisengageScaleMode();
}

// Make this return true when this Command no longer needs to run execute()
bool ShiftScaleToDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ShiftScaleToDrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShiftScaleToDrive::Interrupted()
{

}
