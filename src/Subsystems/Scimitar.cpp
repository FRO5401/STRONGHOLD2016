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

const int ScimitarSpeed	=	0.9;
const int ScimPrecision =   0.5;

const float ScimitarRightEncDPP = 1;
const float ScimitarLeftEncDPP  = 1;

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

	SmartDashboard::PutNumber("SCIM Max", MaxPosition);
	SmartDashboard::PutNumber("SCIM Min", MinPosition);
	SmartDashboard::PutNumber("SCIM WithinFrame", WithinFramePos);

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

	if (!Override){
	//	if (!(RightCloseLimit->Get() && LeftCloseLimit->Get())) //runs if close limits aren't triggered
	//		if (ReportPosition() > MinPosition && ReportPosition() < WithinFramePos) //Keeps us within frame perimeter
				Move(ScimChange);
	} else {
	//	if (!((RightFarLimit->Get() && LeftFarLimit->Get()) || (RightCloseLimit->Get() && LeftCloseLimit->Get()))) //runs if neither set of switches are hit
	//		if (ReportPosition() > MinPosition && ReportPosition() < MaxPosition) //Keeps us from breaking the scimitar
				Move(ScimChange);
	}

	SmartDashboard::PutNumber("ScimitarLeftEnc Distance", ReportLeftPosition());
	SmartDashboard::PutNumber("ScimitarRightEnc Distance", ReportRightPosition());
/*	SmartDashboard::PutBoolean("RightCloseLimit", RightCloseLimit->Get());
	SmartDashboard::PutBoolean("LeftCloseLimit", LeftCloseLimit->Get());
	SmartDashboard::PutBoolean("RightFarLimit", RightFarLimit->Get());
	SmartDashboard::PutBoolean("LeftFarLimit", LeftFarLimit->Get());*/
}

void Scimitar::Move(double ScimChange){
	LeftScimitarExtender -> Set(ScimChange);
	RightScimitarExtender -> Set(ScimChange);
}

double Scimitar::ReportLeftPosition(){
	return ScimitarLeftEnc ->GetDistance();
}

double Scimitar::ReportRightPosition(){
	return ScimitarRightEnc -> GetDistance();
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
