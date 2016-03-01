#include "SPTShootingPosition.h"

SPTShootingPosition::SPTShootingPosition()
{
	Requires(spt);
}

// Called just before this Command runs the first time
void SPTShootingPosition::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SPTShootingPosition::Execute()
{
	spt -> ClearShooterPathPosition();
}

// Make this return true when this Command no longer needs to run execute()
bool SPTShootingPosition::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SPTShootingPosition::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SPTShootingPosition::Interrupted()
{

}


