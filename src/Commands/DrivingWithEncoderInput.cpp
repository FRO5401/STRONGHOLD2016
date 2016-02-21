#include "DrivingWithEncoderInput.h"

DrivingWithEncoderInput::DrivingWithEncoderInput()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(drivebase);
}

// Called just before this Command runs the first time
void DrivingWithEncoderInput::Initialize()
{
//	drivebase -> EncoderDrive(); //KJM Not sure we want to call this from initialization
//	drivebase -> Reset();	//Can't do this in final code as gyro will get reset again when we go into teleop
}

// Called repeatedly when this Command is scheduled to run
void DrivingWithEncoderInput::Execute()
{
/*
	//Put it in the DriveBase Subsystem
	//My logic
	//First line will get the Distance that the driver wants to drive from the SmartDashboard
	SmartDashboard::GetNumber("Distance for Encoder Drive", DistanceForEncoderDrive);
	//SEcond line zeros the encoder, so the start position is 0
	drivebase -> EncoderReset();
	//This while loop will make //This while loop will make  //KJM Can remove the loop, the function within DriveBase performs this
	while(DistanceForEncoderDrive != (LeftEnc -> GetDistance()))
		{ */
//			drivebase -> AutoDriveDistanceDrive(Distance);  //TODO Want to figure out how to take a parameter into the command and then pass it here
		//}

}

// Make this return true when this Command no longer needs to run execute()
bool DrivingWithEncoderInput::IsFinished()
{
	//New stuff
	return true;
}

// Called once after isFinished returns true
void DrivingWithEncoderInput::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DrivingWithEncoderInput::Interrupted()
{

}
