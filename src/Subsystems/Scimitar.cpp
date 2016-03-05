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

const double MaxPosition = 0;
const double MinPosition = 0;

double ScimitarEncDPP = 1;

Scimitar::Scimitar() :
		Subsystem("Scimitar")
{
	ScimitarExtender 	= new Victor(Scimitar_Channel);
	ScimitarEnc			= new Encoder(Enc_Scimitar_A, Enc_Scimitar_B, true, Encoder::k1X);
}

void Scimitar::InitDefaultCommand()
{
	SetDefaultCommand(new ScimitarInOut());
};

void Scimitar::Extend(double ScimChange)
{
	double CurrentPosition = ReportPosition();
	//Zero out the change if angle is at its upper limit and trying to increase
	ScimChange = ((ScimChange < 0) && (CurrentPosition >= MaxPosition)) ? 0 : ScimChange;
	//Zero out the change if angle is at its lower limit and trying to decrease
	ScimChange = ((ScimChange > 0) && (CurrentPosition <= MaxPosition)) ? 0 : ScimChange;
}

double Scimitar::ReportPosition(){
	return ScimitarEnc ->GetDistance();
}

void Scimitar::ResetEncoder(){
	ScimitarEnc -> Reset();
	ScimitarEnc -> SetDistancePerPulse(ScimitarEncDPP);
}
