#include "AbortReach.h"

AbortReach::AbortReach()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(scimitar);
}

// Called just before this Command runs the first time
void AbortReach::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AbortReach::Execute()
{
	scimitar	->	Extend(false);
}

// Make this return true when this Command no longer needs to run execute()
bool AbortReach::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AbortReach::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AbortReach::Interrupted()
{

}
