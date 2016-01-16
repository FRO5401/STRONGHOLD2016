#include "UpAndDownInfeeder.h"

UpAndDownInfeeder::UpAndDownInfeeder()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(spt);
}

// Called just before this Command runs the first time
void UpAndDownInfeeder::Initialize()
{
	//Plans on needing to WhilePressed() either the joystick or D-pad
	//Gets the value of up or down
	double UpOrDownValue = oi -> GetUpOrDownValueInfeeder();
	//Tells the Infeeder to go up or down
	spt -> UpAndDown(UpOrDownValue);
}

// Called repeatedly when this Command is scheduled to run
void UpAndDownInfeeder::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool UpAndDownInfeeder::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void UpAndDownInfeeder::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpAndDownInfeeder::Interrupted()
{

}