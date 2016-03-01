#include "GyroCalibration.h"
#include <DriverStation.h>

GyroCalibration::GyroCalibration()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(drivebase);
	DS -> GetInstance();
}

// Called just before this Command runs the first time
void GyroCalibration::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void GyroCalibration::Execute()
{
	bool TestMode = DS -> IsTest();//Uses DS to make variable true depending if it is in test mode or not
		//Calibrates depending on TestMode status
		if(TestMode)
			drivebase -> MainGyro -> Calibrate();
}

// Make this return true when this Command no longer needs to run execute()
bool GyroCalibration::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void GyroCalibration::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GyroCalibration::Interrupted()
{

}
