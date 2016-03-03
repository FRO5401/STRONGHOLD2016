#include "AutoDriveCommand.h"

const double AutoDistThresh	= 2; 		//Distance threshold in inches //TODO Must tune this
const float kPLeft = .835;	//For going forwards
const float kPRight = .9; //For going backwards
const double AutoDriveSpeed	= 0.5;

AutoDriveCommand::AutoDriveCommand(float DistanceInput)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivebase);
	DesiredDistance = DistanceInput;
	DistanceTraveled = 0;
	DoneTraveling = true;
}

// Called just before this Command runs the first time
void AutoDriveCommand::Initialize()
{

	drivebase -> EncoderReset();
	//MainGyro -> Reset();
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveCommand::Execute()
{
	if (fabs(DesiredDistance) <= AutoDistThresh){
		std::cout << "DesiredDistance too small!!!\n";
		DoneTraveling = true;
	} else {
		//	while ((DesiredDistance > 0) ? (DistanceTraveled < fabs(DesiredDistance) - AutoDistThresh) : (DistanceTraveled > AutoDistThresh - fabs(DesiredDistance))){
			if ((DistanceTraveled < fabs(DesiredDistance) - AutoDistThresh) && DesiredDistance > 0){ //DesiredDistance is positive, go forward
				drivebase -> Drive(AutoDriveSpeed * kPLeft, AutoDriveSpeed);
				DoneTraveling = false;
			} else if ((DistanceTraveled > AutoDistThresh - fabs(DesiredDistance)) && DesiredDistance < 0){ //DesiredDistance is negative, go backward
				drivebase -> Drive(-AutoDriveSpeed, -AutoDriveSpeed * kPRight);//There is no kp value here because the kp value makes the robot run curved when going backwards
				DoneTraveling = true;
			} else { //error or exactly 0
				//std::cout << "AutoDriveDistance Error!!!\n";
				DoneTraveling = true;
			}
		DistanceTraveled = (drivebase -> RightEnc -> GetDistance());//XXX TODO re-add leftenc for competition robot
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
	drivebase -> Stop(); //idk if needed
}

