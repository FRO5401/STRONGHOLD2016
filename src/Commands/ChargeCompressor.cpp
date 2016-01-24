#include "ChargeCompressor.h"

ChargeCompressor::ChargeCompressor()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(offboardcompressor);
}

// Called just before this Command runs the first time
void ChargeCompressor::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ChargeCompressor::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ChargeCompressor::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ChargeCompressor::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ChargeCompressor::Interrupted()
{

}
