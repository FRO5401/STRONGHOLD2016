#include "InfeederLiftIntoInfeederPosition.h"

InfeederLiftIntoInfeederPosition::InfeederLiftIntoInfeederPosition()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(spt);
}

// Called just before this Command runs the first time
void InfeederLiftIntoInfeederPosition::Initialize()
{
//	spt -> MoveToInfeederPosition();
}

// Called repeatedly when this Command is scheduled to run
void InfeederLiftIntoInfeederPosition::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool InfeederLiftIntoInfeederPosition::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void InfeederLiftIntoInfeederPosition::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void InfeederLiftIntoInfeederPosition::Interrupted()
{

}
