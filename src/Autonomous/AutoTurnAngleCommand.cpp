#include "AutoTurnAngleCommand.h"

const double AngleThreshold	= 2; 		//Turn angle in degrees
const double AutoDistThresh	= 2; 		//Distance threshold in inches
const double AutoTurnSpeed	= 0.95;
const double AutoTurnPrecision = .5;

AutoTurnAngleCommand::AutoTurnAngleCommand(float Angle)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(drivebase);
	DesiredTurnAngle = Angle;
	//XXX Switched to using ReportGyro rather than the raw value; if there's problems, have ReportGyro return MainGyro -> GetAngle()
	CurrentAngle = 0;
	InitAngle = 0;
	Finished = true;
}

// Called just before this Command runs the first time
void AutoTurnAngleCommand::Initialize()
{
	InitAngle = drivebase -> ReportGyro();
}

// Called repeatedly when this Command is scheduled to run
void AutoTurnAngleCommand::Execute()
{
	if (fabs(DesiredTurnAngle) <= AngleThreshold){
		std::cout << "DesiredTurnAngle too small!!!\n";
		Finished = true;
	} else {
		if (DesiredTurnAngle > 0 && (CurrentAngle < fabs(DesiredTurnAngle) - AngleThreshold)){
			drivebase -> Drive(AutoTurnSpeed * AutoTurnPrecision, -AutoTurnSpeed * AutoTurnPrecision);
			Finished = false;
		} else if (DesiredTurnAngle < 0 && (CurrentAngle > AngleThreshold - fabs(DesiredTurnAngle))) {
			drivebase -> Drive(-AutoTurnSpeed * AutoTurnPrecision, AutoTurnSpeed * AutoTurnPrecision);
			Finished = false;
		} else { //error or exactly 0
			std::cout << "AutoTurnAngle Finished\n";
			Finished = true;
		}
	CurrentAngle = drivebase -> ReportGyro() - InitAngle;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurnAngleCommand::IsFinished()
{
	return Finished;
}

// Called once after isFinished returns true
void AutoTurnAngleCommand::End()
{
	drivebase -> Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurnAngleCommand::Interrupted()
{
	drivebase -> Stop();
}
