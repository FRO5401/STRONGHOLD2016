#include "RetractHook.h"

RetractHook::RetractHook()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(shorthook);
}

// Called just before this Command runs the first time
void RetractHook::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RetractHook::Execute()
{
	shorthook	->	Extend(false);
}

// Make this return true when this Command no longer needs to run execute()
bool RetractHook::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RetractHook::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RetractHook::Interrupted()
{

}
