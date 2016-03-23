#include "ReachForBar.h"

ReachForBar::ReachForBar()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(scimitar);
}

// Called just before this Command runs the first time
void ReachForBar::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ReachForBar::Execute()
{
	//scimitar	->	Extend(true);
}

// Make this return true when this Command no longer needs to run execute()
bool ReachForBar::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ReachForBar::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ReachForBar::Interrupted()
{

}
