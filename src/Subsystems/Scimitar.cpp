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
const double ScimPrecision =   0.2;

const double ScimitarRightEncDPP = 7.5 / 162914;
const double ScimitarLeftEncDPP  = 8.125 / 176036;

//TODO Must temper enc values so that one does not gain on the other

Scimitar::Scimitar() :
		Subsystem("Scimitar")
{
	RightScimitarExtender 	= new Victor(RightScimitar_Channel);
	LeftScimitarExtender 	= new Victor(LeftScimitar_Channel);
	ScimitarLeftEnc			= new Encoder(Left_Enc_Scimitar_A, Left_Enc_Scimitar_B, true, Encoder::k1X);
	ScimitarRightEnc		= new Encoder(Right_Enc_Scimitar_A, Right_Enc_Scimitar_B, true, Encoder::k1X);

	MaxPosition = 0;
	MinPosition = 0;
	WithinFramePos = 0;
	OnBumperPos = 0;

	SmartDashboard::PutNumber("SCIM Max", MaxPosition);
	SmartDashboard::PutNumber("SCIM Min", MinPosition);
	SmartDashboard::PutNumber("SCIM WithinFrame", WithinFramePos);

	SmartDashboard::PutNumber("ScimitarLeftEnc Distance", ReportLeftPosition());
	SmartDashboard::PutNumber("ScimitarRightEnc Distance", ReportRightPosition());

/*	RightFarLimit = new DigitalInput(RightFarLimit_Channel);
	RightCloseLimit = new DigitalInput(RightCloseLimit_Channel);
	LeftFarLimit = new DigitalInput(LeftFarLimit_Channel);
	LeftCloseLimit = new DigitalInput(LeftCloseLimit_Channel);
*/
}

void Scimitar::InitDefaultCommand()
{
	SetDefaultCommand(new ScimitarInOut());
	ResetEncoders();
}

void Scimitar::Control(double ScimChange, bool Override)
{
	SmartDashboard::PutNumber("SCIM Max", MaxPosition);
	SmartDashboard::PutNumber("SCIM Min", MinPosition);
	SmartDashboard::PutNumber("SCIM WithinFrame", WithinFramePos);

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
	SmartDashboard::PutNumber("ScimChange in Control", ScimChange);
	Move(ScimChange);

	SmartDashboard::PutNumber("ScimitarLeftEnc Distance", ReportLeftPosition());
	SmartDashboard::PutNumber("ScimitarRightEnc Distance", ReportRightPosition());
/*	SmartDashboard::PutBoolean("RightCloseLimit", RightCloseLimit->Get());
	SmartDashboard::PutBoolean("LeftCloseLimit", LeftCloseLimit->Get());
	SmartDashboard::PutBoolean("RightFarLimit", RightFarLimit->Get());
	SmartDashboard::PutBoolean("LeftFarLimit", LeftFarLimit->Get());*/
}

void Scimitar::Move(double ScimChangeValue){
	ScimChangeValue *= ScimPrecision;
	SmartDashboard::PutNumber("ScimChangeValue", ScimChangeValue);
	LeftScimitarExtender -> Set(ScimChangeValue);
	RightScimitarExtender -> Set(ScimChangeValue);
}

void Scimitar::MoveLeft(double ScimChange){
	LeftScimitarExtender -> Set(ScimChange);
}

void Scimitar::MoveRight(double ScimChange){
	RightScimitarExtender -> Set(ScimChange);
}

double Scimitar::ReportLeftPosition(){
	SmartDashboard::PutNumber("SCIM LeftEnc Raw", ScimitarLeftEnc -> Get());
	return ScimitarLeftEnc ->GetDistance();
}

double Scimitar::ReportRightPosition(){
	SmartDashboard::PutNumber("SCIM RightEnc Raw", ScimitarRightEnc -> Get());
	return ScimitarRightEnc -> GetDistance();
}

bool Scimitar::CheckCloseLimit(){
//	return (RightFarLimit->Get() && LeftFarLimit->Get());
	return false;
}

bool Scimitar::CheckFarLimit(){
//	return (RightFarLimit->Get() && LeftFarLimit->Get());
	return false;
}

bool Scimitar::CheckLimitSwitches(){
//	return !(CheckCloseLimit() || CheckFarLimit());
	return false;
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
