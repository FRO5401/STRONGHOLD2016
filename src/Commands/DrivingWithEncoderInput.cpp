#include "DrivingWithEncoderInput.h"

DrivingWithEncoderInput::DrivingWithEncoderInput()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(drivebase);
}

// Called just before this Command runs the first time
void DrivingWithEncoderInput::Initialize(double DriveDistance)
{
	drivebase -> EncoderDrive(DriveDistance);
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
	//This while loop will make
	while(DistanceForEncoderDrive != (LeftEnc -> GetDistance()))
		{
			drivebase -> EncoderDrive(double(DistanceForEncoderDrive - LeftEnc -> GetDistance()));
		}
*/
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
