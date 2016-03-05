#include "ScimitarUpDown.h"

const int Up = 1;
const int Down = -1;


ScimitarUpDown::ScimitarUpDown()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(hookshoulder);
	DpadDirection = 0;
}

// Called just before this Command runs the first time
void ScimitarUpDown::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ScimitarUpDown::Execute()
{
	DpadDirection = oi -> GetMOHPOVState();
	if (DpadDirection == 0){
		hookshoulder -> UpAndDown(0);
	} else 	if (DpadDirection == 1){
		hookshoulder -> UpAndDown(Up);
	} else if (DpadDirection == -1){
		hookshoulder-> UpAndDown(Down);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool ScimitarUpDown::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ScimitarUpDown::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScimitarUpDown::Interrupted()
{

}
