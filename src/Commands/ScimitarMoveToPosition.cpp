#include "ScimitarMoveToPosition.h"

const double DistanceThreshold = .25; //inches

ScimitarMoveToPosition::ScimitarMoveToPosition(double desired)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(scimitar);
	Finished = true;
	DesiredPosition = desired;
}

// Called just before this Command runs the first time
void ScimitarMoveToPosition::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ScimitarMoveToPosition::Execute()
{
/*	CurrentPosition = (scimitar -> ReportLeftPosition() + scimitar -> ReportRightPosition()) / 2;
	if (CurrentPosition > DesiredPosition + DistanceThreshold){ //Retract
		scimitar -> Control(1, 1, false);
	} else if (CurrentPosition < DesiredPosition - DistanceThreshold){ //Extend
		scimitar -> Control(-1, -1, false);
	} else {
		Finished = true;
	} */

}

// Make this return true when this Command no longer needs to run execute()
bool ScimitarMoveToPosition::IsFinished()
{
	return Finished;
}

// Called once after isFinished returns true
void ScimitarMoveToPosition::End()
{
	scimitar -> Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScimitarMoveToPosition::Interrupted()
{
	scimitar -> Stop();
}
