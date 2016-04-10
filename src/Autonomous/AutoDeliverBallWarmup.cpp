#include "AutoDeliverBallWarmup.h"

AutoDeliverBallWarmup::AutoDeliverBallWarmup(float t)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(feeder);
	FeedTime = t;

}

// Called just before this Command runs the first time
void AutoDeliverBallWarmup::Initialize()
{

	SetTimeout(FeedTime);

}

// Called repeatedly when this Command is scheduled to run
void AutoDeliverBallWarmup::Execute()
{
	feeder -> FeedInFromField();

}

// Make this return true when this Command no longer needs to run execute()
bool AutoDeliverBallWarmup::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoDeliverBallWarmup::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDeliverBallWarmup::Interrupted()
{

}
