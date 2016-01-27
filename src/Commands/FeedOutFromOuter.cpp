#include "FeedOutFromOuter.h"

FeedOutFromOuter::FeedOutFromOuter()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(feeder);
}

// Called just before this Command runs the first time
void FeedOutFromOuter::Initialize()
{
	feeder -> FeedOutToField();
}

// Called repeatedly when this Command is scheduled to run
void FeedOutFromOuter::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool FeedOutFromOuter::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void FeedOutFromOuter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FeedOutFromOuter::Interrupted()
{

}
