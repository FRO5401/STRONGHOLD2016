#include "ChargeCompressor.h"
#include <DriverStation.h>

ChargeCompressor::ChargeCompressor()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(offboardcompressor);
	DS -> GetInstance();//Makes DS pointer which is similar to how "oi" is used in DriveBase
						//Various methods from DriveStation can be used on DS
}

// Called just before this Command runs the first time
void ChargeCompressor::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ChargeCompressor::Execute()
{
	bool TestMode = DS -> IsTest();//Uses DS to make variable true depending if it is in test mode or not
	//Turns compressor on or off depending on testmode
	if(TestMode){
		offboardcompressor -> CompressorOn();
	}else if(!TestMode) {
		offboardcompressor -> CompressorOff();
	}
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
