#include "FeedOutFromInner.h"

FeedOutFromInner::FeedOutFromInner()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(feeder);
}

// Called just before this Command runs the first time
void FeedOutFromInner::Initialize()
{
	feeder -> FeedOutFromShooter();
}

// Called repeatedly when this Command is scheduled to run
void FeedOutFromInner::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool FeedOutFromInner::IsFinished()
{
	return	true;
}

// Called once after isFinished returns true
void FeedOutFromInner::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void FeedOutFromInner::Interrupted()
{

}
