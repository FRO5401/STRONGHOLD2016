#include "InfeederLiftIntoDelivery.h"

InfeederLiftIntoDelivery::InfeederLiftIntoDelivery()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(spt);
}

// Called just before this Command runs the first time
void InfeederLiftIntoDelivery::Initialize()
{
//	spt -> MoveToDeliveryPosition();
}

// Called repeatedly when this Command is scheduled to run
void InfeederLiftIntoDelivery::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool InfeederLiftIntoDelivery::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void InfeederLiftIntoDelivery::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void InfeederLiftIntoDelivery::Interrupted()
{

}
