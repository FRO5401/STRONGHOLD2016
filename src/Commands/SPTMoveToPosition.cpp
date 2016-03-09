#include "SPTMoveToPosition.h"

const float SPTAngleTolerance = 2;

SPTMoveToPosition::SPTMoveToPosition(float angle)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(spt);
	finished = true;
	DesiredAngle = angle;
}

// Called just before this Command runs the first time
void SPTMoveToPosition::Initialize()
{
	//spt -> Stop();
}

// Called repeatedly when this Command is scheduled to run
void SPTMoveToPosition::Execute()
{
	if (spt -> ReportAngle() > DesiredAngle + SPTAngleTolerance){
		spt -> UpAndDown(1, false); //positive value goes down
		finished = false;
	} else if (spt ->ReportAngle() < DesiredAngle - SPTAngleTolerance){
		spt -> UpAndDown(-1, false); //negative value goes up
		finished = false;
	} else {
		finished = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool SPTMoveToPosition::IsFinished()
{
	return finished;
}

// Called once after isFinished returns true
void SPTMoveToPosition::End()
{
	spt ->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SPTMoveToPosition::Interrupted()
{
	spt ->Stop();
}
