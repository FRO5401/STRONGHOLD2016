#include "FeedInFromOuter.h"

FeedInFromOuter::FeedInFromOuter()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(feeder);
}

// Called just before this Command runs the first time
void FeedInFromOuter::Initialize()
{
	feeder -> FeedInFromField();
}

// Called repeatedly when this Command is scheduled to run
void FeedInFromOuter::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool FeedInFromOuter::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void FeedInFromOuter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FeedInFromOuter::Interrupted()
{

}
