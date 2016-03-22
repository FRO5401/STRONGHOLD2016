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

const double MaxPosition = 0;
const double MinPosition = 0;
const double WithinFramePos = 0;

double ScimitarEncDPP = 1;

//Must temper enc values so that one does not gain on the other

Scimitar::Scimitar() :
		Subsystem("Scimitar")
{
	RightScimitarExtender 	= new Victor(RightScimitar_Channel);
	LeftScimitarExtender 	= new Victor(LeftScimitar_Channel);
	ScimitarEnc			= new Encoder(Enc_Scimitar_A, Enc_Scimitar_B, true, Encoder::k1X);
	ResetEncoder();

	RightFarLimit = new DigitalInput(RightFarLimit_Channel);
	RightCloseLimit = new DigitalInput(RightCloseLimit_Channel);
	LeftFarLimit = new DigitalInput(LeftFarLimit_Channel);
	LeftCloseLimit = new DigitalInput(LeftCloseLimit_Channel);

}

void Scimitar::InitDefaultCommand()
{
	SetDefaultCommand(new ScimitarInOut());
}

void Scimitar::Extend(double ScimChange, bool Override)
{
	if (!Override){
		if (!(RightCloseLimit->Get() && LeftCloseLimit->Get())) //runs if close limits aren't triggered
			if (ReportPosition() > MinPosition && ReportPosition() < WithinFramePos) //Keeps us within frame perimeter
				Extend(ScimChange);
	} else {
		if (!((RightFarLimit->Get() && LeftFarLimit->Get()) || (RightCloseLimit->Get() && LeftCloseLimit->Get()))) //runs if neither set of switches are hit
			if (ReportPosition() > MinPosition && ReportPosition() < MaxPosition) //Keeps us from breaking the scimitar
				Extend(ScimChange);
	}

	SmartDashboard::PutNumber("ScimitarEnc Distance", ReportPosition());
	SmartDashboard::PutBoolean("RightCloseLimit", RightCloseLimit->Get());
	SmartDashboard::PutBoolean("LeftCloseLimit", LeftCloseLimit->Get());
	SmartDashboard::PutBoolean("RightFarLimit", RightFarLimit->Get());
	SmartDashboard::PutBoolean("LeftFarLimit", LeftFarLimit->Get());
}

void Scimitar::Extend(double ScimChange){
	LeftScimitarExtender -> Set(ScimChange * ScimPrecision);
	RightScimitarExtender -> Set(ScimChange * ScimPrecision);
}

double Scimitar::ReportPosition(){
	return ScimitarEnc ->GetDistance();
}

void Scimitar::ResetEncoder(){
	ScimitarEnc -> Reset();
	ScimitarEnc -> SetDistancePerPulse(ScimitarEncDPP);
}

void Scimitar::Stop(){
	Extend(0);
}
