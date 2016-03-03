#include "MoveSPTtoPosition.h"

MoveSPTtoPosition::MoveSPTtoPosition(float angle)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(spt);
	finished = true;
	DesiredAngle = angle;
}

// Called just before this Command runs the first time
void MoveSPTtoPosition::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void MoveSPTtoPosition::Execute()
{
	/*if (spt -> GetAdjustedEncDistance() > DesiredAngle + SPTAngleTolerance){
		spt -> SPTShoulderMotor -> Set(SPTMotorSpeed * SPTPrecision); //positive value goes down
		finished = false;
	} else if (spt ->GetAdjustedEncDistance() < DesiredAngle - SPTAngleTolerance){
		spt -> SPTShoulderMotor -> Set(-SPTMotorSpeed * SPTPrecision); //negative value goes up
		finished = false;
	} else {
		finished = true;
	}*/
}

// Make this return true when this Command no longer needs to run execute()
bool MoveSPTtoPosition::IsFinished()
{
	return finished;
}

// Called once after isFinished returns true
void MoveSPTtoPosition::End()
{
	//spt ->SPTShoulderMotor -> Set(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveSPTtoPosition::Interrupted()
{
	//spt ->SPTShoulderMotor -> Set(0);
}
