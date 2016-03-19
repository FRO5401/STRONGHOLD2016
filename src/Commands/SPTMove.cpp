#include "SPTMove.h"

SPTMove::SPTMove()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(spt);
}

// Called just before this Command runs the first time
void SPTMove::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SPTMove::Execute()
{
	bool SPT_Override = (oi	->	GetMOHButtonL3());
	double UpOrDownValue = oi -> GetUpOrDownValueInfeeder();

	//Tells the Infeeder to go up or down
	spt -> UpAndDown(UpOrDownValue, SPT_Override);
}

// Make this return true when this Command no longer needs to run execute()
bool SPTMove::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SPTMove::End()
{
	spt -> Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SPTMove::Interrupted()
{
	spt -> Stop();
}
