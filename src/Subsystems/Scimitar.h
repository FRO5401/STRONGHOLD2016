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
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Victor *RightScimitarExtender;	//Variable for motor to extend the scimitar to scale the tower
	Victor *LeftScimitarExtender;
	Encoder *ScimitarRightEnc;
	Encoder *ScimitarLeftEnc;

	float ScimitarLeftEncDPP;
	float ScimitarRightEncDPP;

	float MaxPosition;
	float MinPosition;
	float WithinFramePos;

	//Limit Switch Variables
/*	DigitalInput *RightFarLimit;
	DigitalInput *RightCloseLimit;
	DigitalInput *LeftFarLimit;
	DigitalInput *LeftCloseLimit;
*/
public:
	Scimitar();
	void InitDefaultCommand();
	void ExtendRetract(double, bool);
	void Control(double, bool);
	void Move(double);
	double ReportLeftPosition();
	double ReportRightPosition();
	void ResetEncoders();
	void Stop();
};

#endif
