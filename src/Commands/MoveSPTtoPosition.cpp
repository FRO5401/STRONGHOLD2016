#include "MoveSPTtoPosition.h"

const float SPTDeliveryPosition 	= 55;//-34.677 from start
const float SPTFeederPosition		= -21;//-112.146 from start
float SPTAngleBuffer = 2;

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
	std::cout << "Moving SPT\n";
	if (spt -> GetAdjustedEncDistance() > DesiredAngle + SPTAngleBuffer){
		spt -> UpAndDown(1, false); //positive value goes down
		finished = false;
	} else if (spt ->GetAdjustedEncDistance() < DesiredAngle - SPTAngleBuffer){
		spt -> UpAndDown(-1, false);//negative value goes up
		finished = false;
	} else {
		finished = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool MoveSPTtoPosition::IsFinished()
{
	return finished;
}

// Called once after isFinished returns true
void MoveSPTtoPosition::End()
{
	spt -> StopForShoot();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveSPTtoPosition::Interrupted()
{
	spt -> StopForShoot();
}
