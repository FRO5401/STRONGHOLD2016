#include "AutonomousAutoTurnAngle.h"

AutonomousAutoTurnAngle::AutonomousAutoTurnAngle(float angle)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(drivebase);
	Angle = angle;
}

// Called just before this Command runs the first time
void AutonomousAutoTurnAngle::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutonomousAutoTurnAngle::Execute()
{
	drivebase -> AutoTurnAngle(Angle, .5); //TODO make second parameter a variable
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousAutoTurnAngle::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutonomousAutoTurnAngle::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousAutoTurnAngle::Interrupted()
{

}
