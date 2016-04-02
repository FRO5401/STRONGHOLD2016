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

//const double ScimitarSpeed	=	0.95; //not used
const double ScimPrecision =   1;

const double ScimitarRightEncDPP = 0.00000989;//Measured: 7.5 / 162914, value is averaged left/right
const double ScimitarLeftEncDPP  = 0.00000919;//Measured: 8.125 / 176036, value averaged left/right;

const double StartingOffset = 0; //TODO Figure out offset from starting position

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
//	ResetEncoders();  //KJM Don't do this here
}

void Scimitar::Control(double LeftScimChange, double RightScimChange, bool Override)
{
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
		std::cout << "Scimitar Far Switch tripped\n";
	}
	//Zero out the change if extension is at its lower limit and trying to decrease
	if ((ReportLeftCloseSwitch() || ReportRightCloseSwitch()) && ((LeftScimChange > 0) || (RightScimChange > 0))){
		LeftScimChange = 0;
		RightScimChange = 0;
		std::cout << "Scimitar Near Swith Tripped\n";
	}
	SmartDashboard::PutNumber("Scim L Input - Adj", LeftScimChange);
	std::cout << "RUNNING SCIMITAR\n";
	LeftScimitarExtender -> Set(LeftScimChange * ScimPrecision);
	RightScimitarExtender -> Set(RightScimChange* ScimPrecision);

}


double Scimitar::ReportLeftPosition(){
	SmartDashboard::PutNumber("SCIM LeftEnc Dist", ScimitarLeftEnc -> GetDistance());
	return ScimitarLeftEnc ->GetDistance() - StartingOffset;
}

double Scimitar::ReportRightPosition(){
	SmartDashboard::PutNumber("SCIM RightEnc Dist", ScimitarRightEnc -> GetDistance());
	return ScimitarRightEnc -> GetDistance() - StartingOffset;
}

double Scimitar::ReportLeftRaw(){
	SmartDashboard::PutNumber("SCIM LeftEnc Raw", ScimitarLeftEnc -> Get());
	return ScimitarLeftEnc ->Get();
}

double Scimitar::ReportRightRaw(){
	SmartDashboard::PutNumber("SCIM RightEnc Raw", ScimitarRightEnc -> Get());
	return ScimitarRightEnc -> Get();
}

//XXX Switches are all reversed because they default to true and go false when tripped
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
	LeftScimitarExtender -> Set(0);
	RightScimitarExtender -> Set(0);
}
