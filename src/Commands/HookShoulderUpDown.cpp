#include "HookShoulderUpDown.h"

const double HookShoulderSpeed = 0.5; //TODO Tune this to a comfortable speed
const double HookMaxPosition = 0; //TODO Set the angle
const double HookMinPosition = 0; //TODO Set the angle

HookShoulderUpDown::HookShoulderUpDown()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(hookshoulder);
	DpadDirection = 0;
	Override = FALSE;
	CurrentPosition = 0;
	HookShoulderMove = 0;
}

// Called just before this Command runs the first time
void HookShoulderUpDown::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void HookShoulderUpDown::Execute()
{
	DpadDirection = oi -> GetMOHPOVState();
	Override = oi -> GetButtonBack();
	CurrentPosition = hookshoulder -> ReportAngle();

	//If wondering about the numbers for the conditionals, look at GetMOHPOVState()
	if (DpadDirection == 0){ //Stops the HookShoulder if D-pad is unpressed or pressed in the wrong section
		HookShoulderMove = 0;
	} else 	if (DpadDirection == 1){//Makes the HookShoulder move the HookShoulder up if D-pad pressed up, moves at 1 degree per loop
		HookShoulderMove = HookShoulderSpeed;
	} else if (DpadDirection == -1){//Makes the HookShoulder move the HookShoulder down if D-pad pressed down, moves at 1 degree per loop
		HookShoulderMove = -HookShoulderSpeed;
	}

	if(!Override)
	{
		//Zero out the change if angle is at its upper limit and trying to increase, <0 = UP?
		HookShoulderMove = ((HookShoulderMove < 0) && (CurrentPosition >= HookMaxPosition)) ? 0 : HookShoulderMove;
		//Zero out the change if angle is at its lower limit and trying to decrease
		HookShoulderMove = ((HookShoulderMove > 0) && (CurrentPosition <= HookMinPosition)) ? 0 : HookShoulderMove;
	}
	//Returns the Angle the HookShoulder is at to the Dashboard
	SmartDashboard::PutNumber("DPadDirection", DpadDirection);
	SmartDashboard::PutNumber("HookShoulder Input", HookShoulderMove);

//	hookshoulder -> UpAndDown(HookShoulderMove,Override); //TODO Took this out to test the dpad inputs, don't trust those
}

// Make this return true when this Command no longer needs to run execute()
bool HookShoulderUpDown::IsFinished()
{
	return false; //Always run
}

// Called once after isFinished returns true
void HookShoulderUpDown::End()
{
	hookshoulder -> StopHookShoulder();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HookShoulderUpDown::Interrupted()
{
	hookshoulder -> StopHookShoulder();
}
