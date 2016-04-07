#include "AutoTurnToAngleCommand.h"

AutoTurnToAngleCommand::AutoTurnToAngleCommand(float AngleInput)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivebase);
	AngleToTurn = AngleInput;
	Timeout = 0;
}

AutoTurnToAngleCommand::AutoTurnToAngleCommand(float AngleInput, float time)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivebase);
	AngleToTurn = AngleInput;
	Timeout = time;
}

// Called just before this Command runs the first time
void AutoTurnToAngleCommand::Initialize()
{
	if (Timeout > 0)
		SetTimeout(Timeout);
}

// Called repeatedly when this Command is scheduled to run
void AutoTurnToAngleCommand::Execute()
{
	std::cout << "AutoTurnToAngleCommand is no longer being used!\n";
}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurnToAngleCommand::IsFinished()
{
	return true;
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
