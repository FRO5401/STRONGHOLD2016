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
	Encoder *ScimitarEnc;

	//Limit Switch Variables
/*	DigitalInput *RightFarLimit;
	DigitalInput *RightCloseLimit;
	DigitalInput *LeftFarLimit;
	DigitalInput *LeftCloseLimit;
*/
public:
	Scimitar();
	void InitDefaultCommand();
	void Extend(double, bool);
	void Extend(double);
	double ReportPosition();
	void ResetEncoder();
	void Stop();
};

#endif
