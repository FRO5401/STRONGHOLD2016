/*
 * Long hook subsystem for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * Extends long enough to scale the castle
 * Oh but if I went 'round sayin' I was Emperor, just because some
 * moistened bint lobbed a scimitar at me, they'd put me away.
 */

#include "Scimitar.h"
#include "../RobotMap.h"
#include "Commands/ScimitarInOut.h"

const double ScimitarSpeed	=	0.9;
const double ScimPrecision =   0.5;

const double ScimitarRightEncDPP = 0.0000461;//Measured: 7.5 / 162914, value is averaged left/right
const double ScimitarLeftEncDPP  = 0.0000461;//Measured: 8.125 / 176036, value averaged left/right;

Scimitar::Scimitar() :
		Subsystem("Scimitar")
{
	RightScimitarExtender 	= new Victor(RightScimitar_Channel);
	LeftScimitarExtender 	= new Victor(LeftScimitar_Channel);
	ScimitarLeftEnc			= new Encoder(Left_Enc_Scimitar_A, Left_Enc_Scimitar_B, true, Encoder::k1X);
	ScimitarRightEnc		= new Encoder(Right_Enc_Scimitar_A, Right_Enc_Scimitar_B, true, Encoder::k1X);
//TODO Find these positions
	MaxPosition = 0;
	MinPosition = 0;
	WithinFramePos = 0; //also starting pos
	OnBumperPos = 0;

	SmartDashboard::PutNumber("SCIM Max", MaxPosition);
	SmartDashboard::PutNumber("SCIM Min", MinPosition);
	SmartDashboard::PutNumber("SCIM WithinFrame", WithinFramePos);

	SmartDashboard::PutNumber("ScimitarLeftEnc Distance", 0);
	SmartDashboard::PutNumber("ScimitarRightEnc Distance", 0);
	SmartDashboard::PutNumber("SCIM LeftEnc Raw", 0);
	SmartDashboard::PutNumber("SCIM RightEnc Raw", 0);
	SmartDashboard::PutBoolean("Scim R Far Limit", FALSE);
	SmartDashboard::PutBoolean("Scim L Far Limit", FALSE);
	SmartDashboard::PutBoolean("Scim R Close Limit", FALSE);
	SmartDashboard::PutBoolean("Scim R Close Limit", FALSE);

	RightFarLimit = new DigitalInput(RightFarLimit_Channel);
	RightCloseLimit = new DigitalInput(RightCloseLimit_Channel);
	LeftFarLimit = new DigitalInput(LeftFarLimit_Channel);
	LeftCloseLimit = new DigitalInput(LeftCloseLimit_Channel);

}

void Scimitar::InitDefaultCommand()
{
	SetDefaultCommand(new ScimitarInOut());
	ResetEncoders();
}

void Scimitar::Control(double LeftScimChange, double RightScimChange, bool Override)
{
//	SmartDashboard::GetNumber("SCIM Max", MaxPosition);
//	SmartDashboard::GetNumber("SCIM Min", MinPosition);
//	SmartDashboard::GetNumber("SCIM WithinFrame", WithinFramePos);

//	if (!Override){ //For use during majority of match
	//	if (CheckLimitSwitches()){ //runs if neither set of limit switches are hit
	//		if ((ReportLeftPosition() > MinPosition && ReportLeftPosition() < WithinFramePos) && (ReportRightPosition() > MinPosition && ReportRightPosition() < WithinFramePos)) //Keeps us within frame perimeter
//				Move(ScimChange * ScimPrecision);
	/*	} else {
			if (CheckCloseLimit()){ //only allow going up
				if (ScimChange > 0)
					Move(ScimChange);
				else
					Stop();
			} else if (CheckFarLimit()){ //only allow going down
				if (ScimChange < 0)
					Move(ScimChange);
				else
					Stop();
			}
		} */
//	} else { //Used during last 15 seconds of match
	//	if (CheckLimitSwitches()){ //runs if neither set of limit switches are hit
	//		if ((ReportLeftPosition() > MinPosition && ReportLeftPosition() < MaxPosition) && (ReportRightPosition() > MinPosition && ReportRightPosition() < MaxPosition)) //Keeps us from breaking the scimitar
//				Move(ScimChange * ScimPrecision);
	/*	} else {
			if (CheckCloseLimit()){ //only allow going up
				if (ScimChange > 0)
					Move(ScimChange);
				else
					Stop();
			} else if (CheckFarLimit()){ //only allow going down
				if (ScimChange < 0)
					Move(ScimChange);
				else
					Stop();
			}
		} */
//	}


	SmartDashboard::PutNumber("ScimitarLeftEnc Distance", ReportLeftPosition());
	SmartDashboard::PutNumber("ScimitarRightEnc Distance", ReportRightPosition());
//	SmartDashboard::PutBoolean("RightCloseLimit", RightCloseLimit->Get());
//	SmartDashboard::PutBoolean("LeftCloseLimit", LeftCloseLimit->Get());
//	SmartDashboard::PutBoolean("RightFarLimit", RightFarLimit->Get());
//	SmartDashboard::PutBoolean("LeftFarLimit", LeftFarLimit->Get());
	//Limit switch stops are in here to prevent
	//Zero out the change if extension is at its upper limit and trying to increase
	SmartDashboard::PutNumber("Scim L Input", LeftScimChange);
	if ((ReportLeftFarSwitch() || ReportRightFarSwitch()) && ((LeftScimChange < 0) || (RightScimChange < 0))){
		LeftScimChange = 0;
		RightScimChange = 0;
	}
	//Zero out the change if extension is at its lower limit and trying to decrease
	if ((ReportLeftCloseSwitch() || ReportRightCloseSwitch()) && ((LeftScimChange > 0) || (RightScimChange > 0))){
		LeftScimChange = 0;
		RightScimChange = 0;
	}
	SmartDashboard::PutNumber("Scim L Input - Adj", LeftScimChange);

	LeftScimitarExtender -> Set(LeftScimChange * ScimPrecision);
	RightScimitarExtender -> Set(RightScimChange* ScimPrecision);

}

void Scimitar::Move(double ScimChangeValue){
/*	ScimChangeValue *= ScimPrecision;
	SmartDashboard::PutNumber("ScimChangeValue", ScimChangeValue);
	SmartDashboard::GetNumber("SCIM KP", kP_Scimitar);

	double error = double(ScimitarLeftEnc -> Get() - ScimitarRightEnc-> Get());

	SmartDashboard::PutNumber("Error", error);

	if(error > 0){
		LeftScimitarExtender -> Set(ScimChangeValue * (error / kP_Scimitar));
		RightScimitarExtender -> Set(ScimChangeValue);
	}else if(error < 0){
		LeftScimitarExtender -> Set(ScimChangeValue);
		RightScimitarExtender -> Set(ScimChangeValue * (fabs(error) / kP_Scimitar));
	}else{
		LeftScimitarExtender -> Set(ScimChangeValue);
		RightScimitarExtender -> Set(ScimChangeValue);
	}
*/
/*	if (ScimitarRightEnc->GetDistance() != 0 && ScimitarLeftEnc -> GetDistance() != 0)
		ratio = 1 - fabs(double(ScimitarRightEnc-> Get()) / double(ScimitarLeftEnc -> Get()));
	else
		ratio = 1;
*/
/*	SmartDashboard::PutNumber("RATIO", ratio);
	SmartDashboard::PutNumber("ScimChangeValue * ratio", ScimChangeValue * ratio);
	LeftScimitarExtender -> Set(ScimChangeValue);
	RightScimitarExtender -> Set(ScimChangeValue);
*/
/*	double LeftPosition = ReportLeftPosition();
	double RightPosition = ReportRightPosition();
	if (LeftPosition > RightPosition) {
		LeftScimitarExtender -> Set(-ScimChangeValue);//Needs to change ScimChangeValue to a permanent value, should go down, thus value is POSITIVE
	} else if (LeftPosition < RightPosition) {
		LeftScimitarExtender -> Set(ScimChangeValue);//Needs to change ScimChangeValue to a permanent value
	} else {
		LeftScimitarExtender -> Set(ScimChangeValue);
		RightScimitarExtender -> Set(ScimChangeValue);
	}
*/
}

void Scimitar::MoveLeft(double ScimChange){
	SmartDashboard::PutNumber("LEFT ScimChange", ScimChange);
	LeftScimitarExtender -> Set(ScimChange);
}

void Scimitar::MoveRight(double ScimChange){
	SmartDashboard::PutNumber("RIGHT ScimChange", ScimChange);
	RightScimitarExtender -> Set(ScimChange);
}

double Scimitar::ReportLeftPosition(){
	SmartDashboard::PutNumber("SCIM LeftEnc Dist", ScimitarLeftEnc -> GetDistance());
	return ScimitarLeftEnc ->GetDistance();
}

double Scimitar::ReportRightPosition(){
	SmartDashboard::PutNumber("SCIM RightEnc Dist", ScimitarRightEnc -> GetDistance());
	return ScimitarRightEnc -> GetDistance();
}

double Scimitar::ReportLeftRaw(){
	SmartDashboard::PutNumber("SCIM LeftEnc Raw", ScimitarLeftEnc -> Get());
	return ScimitarLeftEnc ->Get();
}

double Scimitar::ReportRightRaw(){
	SmartDashboard::PutNumber("SCIM RightEnc Raw", ScimitarRightEnc -> Get());
	return ScimitarRightEnc -> Get();
}

bool Scimitar::ReportRightFarSwitch(){
	SmartDashboard::PutBoolean("Scim R Far Limit", !(RightFarLimit->Get()));
	return !(RightFarLimit->Get());
}

bool Scimitar::ReportRightCloseSwitch(){
	SmartDashboard::PutBoolean("Scim R Close Limit", !(RightCloseLimit->Get()));
	return !(RightCloseLimit->Get());
}

bool Scimitar::ReportLeftFarSwitch(){
	SmartDashboard::PutBoolean("Scim L Far Limit", !(LeftFarLimit->Get()));
	return !(LeftFarLimit->Get());
}

bool Scimitar::ReportLeftCloseSwitch(){
	SmartDashboard::PutBoolean("Scim L Close Limit", !(LeftCloseLimit->Get()));
	return !(LeftCloseLimit->Get());
}

bool Scimitar::ReportAnySwitches(){
	bool Any = (RightFarLimit -> Get()) || (RightCloseLimit -> Get()) || (LeftFarLimit -> Get()) || (LeftCloseLimit -> Get());

	return !Any;
}

void Scimitar::ResetEncoders(){
	ScimitarLeftEnc -> Reset();
	ScimitarRightEnc -> Reset();
	ScimitarRightEnc -> SetDistancePerPulse(ScimitarRightEncDPP);
	ScimitarLeftEnc -> SetDistancePerPulse(ScimitarLeftEncDPP);
}

void Scimitar::Stop(){
	Move(0);
}
