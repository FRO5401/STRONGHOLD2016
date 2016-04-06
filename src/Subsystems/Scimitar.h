/*
 * Long hook subsystem header for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 */

#ifndef Scimitar_H
#define Scimitar_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Scimitar: public Subsystem
{
private:
	Victor *RightScimitarExtender;	//Variable for motor to extend the scimitar to scale the tower
	Victor *LeftScimitarExtender;
	Encoder *ScimitarRightEnc;
	Encoder *ScimitarLeftEnc;
	//Limit Switches
	DigitalInput *RightFarLimit;
	DigitalInput *RightCloseLimit;
	DigitalInput *LeftFarLimit;
	DigitalInput *LeftCloseLimit;

	float MaxPosition;
	float MinPosition;
	float WithinFramePos;
	float OnBumperPos;
	double ratio;
	double kP_Scimitar;


public:
	Scimitar();
	void InitDefaultCommand();
	void Control(double, double, bool);
	double ReportLeftPosition();
	double ReportRightPosition();
	double ReportLeftRaw();
	double ReportRightRaw();
	bool ReportRightFarSwitch();
	bool ReportRightCloseSwitch();
	bool ReportLeftFarSwitch();
	bool ReportLeftCloseSwitch();
	bool ReportAnySwitches();
	void ResetEncoders();
	void Stop();
};

#endif
