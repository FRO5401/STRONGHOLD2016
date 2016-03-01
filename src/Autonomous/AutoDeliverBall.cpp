#include "AutoDeliverBall.h"

AutoDeliverBall::AutoDeliverBall(float t)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(feeder);
	FeedTime = t;
}

// Called just before this Command runs the first time
void AutoDeliverBall::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoDeliverBall::Execute()
{

	feeder -> FeedOutFromShooter();
	Wait(FeedTime);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDeliverBall::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void AutoDeliverBall::End()
{
	feeder -> StopFeed();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDeliverBall::Interrupted()
{

}
