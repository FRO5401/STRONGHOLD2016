#include "SPTShootingPosition.h"

float SPTDeliveryPositionA 	= 55;//-34.677 from start
float SPTMotorSpeedA = .9;
double SPTPrecisionA = 0.5;
const int Down = -1;

SPTShootingPosition::SPTShootingPosition()
{
	Requires(spt);
	Finished = true;
}

// Called just before this Command runs the first time
void SPTShootingPosition::Initialize()
{
	//spt -> StopForShoot();
}

// Called repeatedly when this Command is scheduled to run
void SPTShootingPosition::Execute()
{
	if (spt->ReportAngle() >= (SPTDeliveryPositionA - 5)){
		spt -> UpAndDown(Down*SPTPrecisionA, false);
		Finished = false;
	} else {
		Finished = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool SPTShootingPosition::IsFinished()
{
	return Finished;
}

// Called once after isFinished returns true
void SPTShootingPosition::End()
{
	spt -> StopForShoot();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SPTShootingPosition::Interrupted()
{
	spt -> StopForShoot();
}


