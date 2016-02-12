#include "AutoTurn.h"
//#include "../RobotMap.h"
const float TurnSpeed		= 0.5;
const float AngleThreshold	= 1;
const float angle			=30; //Remove once we figure out how to pass it as a parameter here
AutoTurn::AutoTurn()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(drivebase);
	gyroAngle = 0; //If value sticks at 0, make sure this isn't reinitializing over and over
}

// Called just before this Command runs the first time
void AutoTurn::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutoTurn::Execute()
{
	gyroAngle = drivebase	->ReportGyro();
	SmartDashboard::PutNumber("Gyro Angle", gyroAngle);

	while (gyroAngle != angle) {
				if (gyroAngle > AngleThreshold)
					drivebase -> Drive(TurnSpeed,-1* TurnSpeed);
				else if (gyroAngle < (-1* AngleThreshold))
					drivebase -> Drive(-1* TurnSpeed,TurnSpeed);
				gyroAngle = drivebase	->ReportGyro();
			}


}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurn::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutoTurn::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurn::Interrupted()
{

}
