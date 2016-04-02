#include "ScimitarInOut.h"

//in inches
const float Setpoint15Inch_Right = 0;//7.75;
const float Setpoint15Inch_Left  = 0;//7.625;
const float Setpoint_NearFull = 24;

const float Precision_NearFull = 0.5; //0.25 is too slow, motors stall
const float PressedPrecision = .5;

ScimitarInOut::ScimitarInOut()
{
	Requires(scimitar);
	LeftEncoderDist 	= 0;
	RightEncoderDist	= 0;
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
//	SmartDashboard::PutBoolean("LeftClose - Cmd", LeftCloseLimit_Cmd);
//	SmartDashboard::PutNumber("MOHRightStickY", 0);
//	SmartDashboard::PutNumber("SCIM RightEnc Raw - Cmd", RightEncoderRaw);
//	SmartDashboard::PutNumber("SCIM LeftEnc Raw - Cmd", LeftEncoderRaw);
	SmartDashboard::PutNumber("Left motor adjusted- Cmd", Left);
	SmartDashboard::PutNumber("Left motor limited - Cmd", Left);
	SmartDashboard::PutBoolean("Extend Override", Override);
	scimitar -> ResetEncoders();
}

// Called just before this Command runs the first time
void ScimitarInOut::Initialize()
{
//	scimitar -> ResetEncoders();//Moving this to the constructor so they don't reset when auto ends and this command resumes
	std::cout << "Initializing Manual Scimitar Extend\n";
}

// Called repeatedly when this Command is scheduled to run
void ScimitarInOut::Execute()
{
	std::cout << "Executing Manual Scimitar Extend\n";
	Input		 		= oi	-> GetMOHPOVState();
	Override 			= oi 	-> GetMOHButtonTriangle();
	SlowScimitar		= oi 	-> GetMOHButtonCircle();
	LeftEncoderDist 	= scimitar -> ReportLeftPosition();
	RightEncoderDist	= scimitar -> ReportRightPosition();
	LeftEncoderRaw 		= scimitar -> ReportLeftRaw();
	RightEncoderRaw 	= scimitar -> ReportRightRaw();
	RightFarLimit_Cmd	= scimitar ->ReportRightFarSwitch();
	RightCloseLimit_Cmd	= scimitar ->ReportRightCloseSwitch();
	LeftFarLimit_Cmd	= scimitar ->ReportLeftFarSwitch();
	LeftCloseLimit_Cmd	= scimitar ->ReportLeftCloseSwitch();
	error				= LeftEncoderRaw - RightEncoderRaw;
//	SmartDashboard::PutBoolean("LeftClose - Cmd", LeftCloseLimit_Cmd);
//	SmartDashboard::PutNumber("MOHRightStickY", Input);
//	SmartDashboard::PutNumber("SCIM RightEnc Raw - Cmd", RightEncoderRaw);
//	SmartDashboard::PutNumber("SCIM LeftEnc Raw - Cmd", LeftEncoderRaw);
//	SmartDashboard::PutNumber("Error", LeftEncoderRaw);
	Left = Input;
	Right = Input;
	if (Input > 0){ //Retract
		if (error > 0){
			Right = K * Right;
		} else if (error < 0 ){
			Left = K * Left;
		}
	} else if (Input < 0){ //Extend
		if (error > 0){
			Left = K * Left;
		} else if (error < 0 ){
			Right = K * Right;
		}
	}
	SmartDashboard::PutNumber("Left motor adjusted- Cmd", Left);
	//Zero out the change if extension is at 15 inch frame perimeter setpoint
	if (!Override){
		if (((RightEncoderDist >= Setpoint15Inch_Right) || (LeftEncoderDist >= Setpoint15Inch_Left)) && ((Left < 0) || (Right < 0))){ //Enc are not beyond limit and we are extending
			Left = 0;
			Right = 0;
			std::cout << "Stop at 15 inch setpoint" ;
		}
	} else {
		std::cout << "Soft Stop Overridden";
	}
	SmartDashboard::PutNumber("Left motor limited - Cmd", Left);
	SmartDashboard::PutBoolean("Extend Override", Override);

	//Slow down the change if extension is near maximum
	if (((RightEncoderDist >= Setpoint_NearFull) || (LeftEncoderDist >= Setpoint_NearFull)) && ((Left < 0) || (Right < 0))){
		Left = Left * Precision_NearFull;
		Right = Right * Precision_NearFull;
		std::cout << "Scimitar Approaching full extension\n";

	}
	//Slow down Scimitar on manual button press
	else if (SlowScimitar){
		Left = Left * PressedPrecision;
		Right = Right * PressedPrecision;
		std::cout << "Scimitar Precision Speed\n";

	}

	std::cout << "Run Manual ScimitarInOut\n";
	scimitar -> Control(Left, Right, Override);
}

// Make this return true when this Command no longer needs to run execute()
bool ScimitarInOut::IsFinished()
{
	std::cout << "Manual Scimitar Extend Check Finish\n";

	return false;
}

// Called once after isFinished returns true
void ScimitarInOut::End()
{
	std::cout << "Manual Scimitar Extend Command Ended\n";
	scimitar -> Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScimitarInOut::Interrupted()
{
	std::cout << "Manual Scimitar Extend Command Interrupted\n";
	scimitar -> Stop();
}
