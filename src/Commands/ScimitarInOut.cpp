#include "ScimitarInOut.h"

ScimitarInOut::ScimitarInOut()
{
	Requires(scimitar);
}

// Called just before this Command runs the first time
void ScimitarInOut::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ScimitarInOut::Execute()
{
	double Input = oi	-> ReadMOHRightStickY();
	//scimitar -> Extend(Input);
}

// Make this return true when this Command no longer needs to run execute()
bool ScimitarInOut::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ScimitarInOut::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScimitarInOut::Interrupted()
{

}
