#include "AutoTurnToAngleCommand.h"

AutoTurnToAngleCommand::AutoTurnToAngleCommand()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivebase);
}

// Called just before this Command runs the first time
void AutoTurnToAngleCommand::Initialize(float AngleToTurn)
{
	drivebase	->	AutoTurnToAngle(AngleToTurn);
}

// Called repeatedly when this Command is scheduled to run
void AutoTurnToAngleCommand::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurnToAngleCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoTurnToAngleCommand::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurnToAngleCommand::Interrupted()
{

}
