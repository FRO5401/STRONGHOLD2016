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
	ScimitarExtender 	= new Victor(Scimitar_Channel);
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
};

void Scimitar::Extend(double ScimChange, bool Override)
{
	if (!Override){
	if (RightCloseLimit->Get() || LeftCloseLimit->Get()) //Should probably use && to be extra sure
		if (ReportPosition() > MinPosition && ReportPosition() < WithinFramePos)
			ScimitarExtender -> Set(ScimChange * ScimPrecision);
	} else {
	if (RightFarLimit->Get() || LeftFarLimit->Get()) //Should probably use && to be extra sure
		if (ReportPosition() > WithinFramePos && ReportPosition() < MaxPosition)
			ScimitarExtender -> Set(ScimChange * ScimPrecision);
	}
}

double Scimitar::ReportPosition(){
	return ScimitarEnc ->GetDistance();
}

void Scimitar::ResetEncoder(){
	ScimitarEnc -> Reset();
	ScimitarEnc -> SetDistancePerPulse(ScimitarEncDPP);
}
