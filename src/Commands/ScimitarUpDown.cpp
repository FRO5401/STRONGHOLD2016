#include "ScimitarUpDown.h"

const int UpMotorSpeed = 0.5;
const int DownMotorSpeed = -0.5;


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

	//If wondering about the numbers for the conditionals, look at GetMOHPOVState()
	if (DpadDirection == 0){ //Stops the HookShoulder if D-pad is unpressed or pressed in the wrong section
		hookshoulder -> UpAndDown(0);
	} else 	if (DpadDirection == 1){//Makes the HookShoulder move the Scimitar up if D-pad pressed up
		hookshoulder -> UpAndDown(UpMotorSpeed);
	} else if (DpadDirection == -1){//Makes the HookShoulder move the Scimitar down if D-pad pressed down
		hookshoulder-> UpAndDown(DownMotorSpeed);
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
