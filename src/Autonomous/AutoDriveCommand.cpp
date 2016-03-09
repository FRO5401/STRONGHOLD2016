#include "AutoDriveCommand.h"

 const float	kP_Right = .9;			//Uncomment for getting value from dashboard
 const float	kP_Left = .835;
 const double AutoDriveSpeed	= 0.5;
 const float DefaultTurnPrecision = 0.5;
 const float AutoDistThresh = 2;
AutoDriveCommand::AutoDriveCommand(float DistanceInput)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivebase);
	DesiredDistance = DistanceInput;
	DoneTraveling = true;
	DistanceTraveled = 0;
}

// Called just before this Command runs the first time
void AutoDriveCommand::Initialize()
{
	drivebase -> EncoderReset();
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveCommand::Execute()
{
	//MainGyro -> Reset();
	if (fabs(DesiredDistance) <= AutoDistThresh){
		std::cout << "DesiredDistance to small!!!\n";
	} else {
			if (DesiredDistance > 0 && (DistanceTraveled < fabs(DesiredDistance) - AutoDistThresh)){ //DesiredDistance is positive, go forward
				drivebase -> Drive(AutoDriveSpeed * kP_Left, AutoDriveSpeed);
				DoneTraveling = false;
			} else if (DesiredDistance < 0 && (DistanceTraveled > AutoDistThresh - fabs(DesiredDistance))){ //DesiredDistance is negative, go backward
				drivebase -> Drive(-AutoDriveSpeed, -AutoDriveSpeed * kP_Right);//There is no kp value here because the kp value makes the robot run curved when going backwards
				DoneTraveling = false;
			} else { //error or exactly 0
				std::cout << "AutoDriveDistance Error!!!\n";
				DoneTraveling = true;
			}
		DistanceTraveled = (drivebase -> GetEncoderDistance());
	}

}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveCommand::IsFinished()
{
	return DoneTraveling;
}

// Called once after isFinished returns true
void AutoDriveCommand::End()
{
	drivebase -> Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveCommand::Interrupted()
{

}

