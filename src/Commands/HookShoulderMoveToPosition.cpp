#include "HookShoulderMoveToPosition.h"

HookShoulderMoveToPosition::HookShoulderMoveToPosition(double angleForHookShoulder)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(hookshoulder);
	finishedHookShoulder = true;
	DesiredAngleHookShoulder = angleForHookShoulder;
}

// Called just before this Command runs the first time
void HookShoulderMoveToPosition::Initialize()
{
	if (hookshoulder -> ReportAngle() > DesiredAngle + SPTAngleTolerance){
		hookshoulder -> UpAndDown(1, false); //positive value goes down
		finished = false;
	} else if (spt ->ReportAngle() < DesiredAngle - SPTAngleTolerance){
		hookshoulder -> UpAndDown(-1, false); //negative value goes up
		finished = false;
	} else {
		finished = true;
	}
}

// Called repeatedly when this Command is scheduled to run
void HookShoulderMoveToPosition::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool HookShoulderMoveToPosition::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void HookShoulderMoveToPosition::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HookShoulderMoveToPosition::Interrupted()
{

}
