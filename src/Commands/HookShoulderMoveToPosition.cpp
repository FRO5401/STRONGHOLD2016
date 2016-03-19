#include "HookShoulderMoveToPosition.h"

const int HookShoulderAngleTolerance = 0;//TODO adjust this

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

}

// Called repeatedly when this Command is scheduled to run
void HookShoulderMoveToPosition::Execute()
{
	if (hookshoulder -> ReportAngle() > DesiredAngleHookShoulder + HookShoulderAngleTolerance){
		hookshoulder -> UpAndDown(-1, false);//Position goes down because desired angle is underneath the current angle
		finishedHookShoulder = false;
	} else if (hookshoulder ->ReportAngle() < DesiredAngleHookShoulder - HookShoulderAngleTolerance){
		hookshoulder -> UpAndDown(1, false); //Position goes up because desired angle is above current angle
		finishedHookShoulder = false;
	} else {
		finishedHookShoulder = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool HookShoulderMoveToPosition::IsFinished()
{
	return finishedHookShoulder;;
}

// Called once after isFinished returns true
void HookShoulderMoveToPosition::End()
{
	hookshoulder -> StopHookShoulder();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HookShoulderMoveToPosition::Interrupted()
{
	hookshoulder -> StopHookShoulder();
}
