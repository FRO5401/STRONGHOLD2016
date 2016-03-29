#include "AutoHookShoulderMove.h"

AutoHookShoulderMove::AutoHookShoulderMove(float DesiredAngle)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(hookshoulder);
	IsFinished = true;
}

// Called just before this Command runs the first time
void AutoHookShoulderMove::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoHookShoulderMove::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AutoHookShoulderMove::IsFinished()
{
	return IsFinished;
}

// Called once after isFinished returns true
void AutoHookShoulderMove::End()
{
	hookshoulder -> StopHookShoulder();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoHookShoulderMove::Interrupted()
{
	hookshoulder -> StopHookShoulder();
}
