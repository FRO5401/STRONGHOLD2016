#include "UpAndDownInfeeder.h"

UpAndDownInfeeder::UpAndDownInfeeder()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(spt);
}

// Called just before this Command runs the first time
void UpAndDownInfeeder::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void UpAndDownInfeeder::Execute()
{
	bool SPT_Override = (oi	->	GetMOHLeftStickButton());

 	//Plans on needing to WhilePressed() either the joystick or D-pad		 	//Plans on needing to WhilePressed() either the joystick or D-pad
 	//Gets the value of up or down		 	//Gets the value of up or down
 	if (!oi->GetMOHButtonL3()){
 		double UpOrDownValue = oi -> GetUpOrDownValueInfeeder();
 		//Tells the Infeeder to go up or down		 		//Tells the Infeeder to go up or down
		spt -> UpAndDown(UpOrDownValue, SPT_Override);
 	}
}

// Make this return true when this Command no longer needs to run execute()
bool UpAndDownInfeeder::IsFinished()
{
	return false;
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
