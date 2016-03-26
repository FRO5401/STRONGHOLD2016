#include "ScimitarInOut.h"

ScimitarInOut::ScimitarInOut()
{
	Requires(scimitar);
	LeftEncoderRaw 	= 0;
	RightEncoderRaw	= 0;
	Left	= 0;
	Right	= 0;
	K 		= 0.75;
	Input	= 0;
	Override = TRUE;
	error	= 0;
	RightFarLimit_Cmd = FALSE;
	RightCloseLimit_Cmd = FALSE;
	LeftFarLimit_Cmd = FALSE;
	LeftCloseLimit_Cmd = FALSE;
	SmartDashboard::PutBoolean("LeftClose - Cmd", LeftCloseLimit_Cmd);
//	SmartDashboard::PutNumber("MOHRightStickY", 0);
//	SmartDashboard::PutNumber("SCIM RightEnc Raw - Cmd", RightEncoderRaw);
//	SmartDashboard::PutNumber("SCIM LeftEnc Raw - Cmd", LeftEncoderRaw);
}

// Called just before this Command runs the first time
void ScimitarInOut::Initialize()
{
	scimitar -> ResetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void ScimitarInOut::Execute()
{
	Input		 		= oi	-> ReadMOHRightStickY();
	Override 		= oi -> GetMOHRightStickButton();
	LeftEncoderRaw 		= scimitar -> ReportLeftRaw();
	RightEncoderRaw 	= scimitar -> ReportRightRaw();
	RightFarLimit_Cmd	= scimitar ->ReportRightFarSwitch();
	RightCloseLimit_Cmd	= scimitar ->ReportRightCloseSwitch();
	LeftFarLimit_Cmd	= scimitar ->ReportLeftFarSwitch();
	LeftCloseLimit_Cmd	= scimitar ->ReportLeftCloseSwitch();
	error			= LeftEncoderRaw - RightEncoderRaw;
	SmartDashboard::PutBoolean("LeftClose - Cmd", LeftCloseLimit_Cmd);
//	SmartDashboard::PutNumber("MOHRightStickY", Input);
//	SmartDashboard::PutNumber("SCIM RightEnc Raw - Cmd", RightEncoderRaw);
//	SmartDashboard::PutNumber("SCIM LeftEnc Raw - Cmd", LeftEncoderRaw);
//	SmartDashboard::PutNumber("Error", LeftEncoderRaw);
	Left = Input;
	Right = Input;
	if (Input > 0){
		if (error > 0){
			Right = K * Right;
		} else if (error < 0 ){
			Left = K * Left;
		}
	} else if (Input < 0){
		if (error > 0){
			Left = K * Left;
		} else if (error < 0 ){
			Right = K * Right;
		}
	}

	//TODO test code Remove this once the encoder equalization is tested, this allows to move just one side for resetting them to even
	if(Override){
		Left = 0;
	}
	//end test code remove
	scimitar -> Control(Left, Right, Override);
//	scimitar -> Move(Input * .2);
}

// Make this return true when this Command no longer needs to run execute()
bool ScimitarInOut::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ScimitarInOut::End()
{
	scimitar -> Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScimitarInOut::Interrupted()
{
	scimitar -> Stop();
}
