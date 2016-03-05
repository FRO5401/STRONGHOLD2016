#include "DeployHook.h"

DeployHook::DeployHook()
{
	// Use Requires() here to declare subsystem dependencies
//	Requires(shorthook);
}

// Called just before this Command runs the first time
void DeployHook::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DeployHook::Execute()
{
//	shorthook	->	Extend(true);
}

// Make this return true when this Command no longer needs to run execute()
bool DeployHook::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DeployHook::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DeployHook::Interrupted()
{

}
