#include "HookBumper.h"

const int BumperPosition	 	= 0;//Position has NOT been calibrated

HookBumper::HookBumper()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(hookshoulder);

}

// Called just before this Command runs the first time
void HookBumper::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void HookBumper::Execute()
{
	hookshoulder        -> MoveToPosition(BumperPosition);

}

// Make this return true when this Command no longer needs to run execute()
bool HookBumper::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void HookBumper::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HookBumper::Interrupted()
{

}
