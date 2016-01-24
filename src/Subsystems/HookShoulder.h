/*
 * Hook shoulder subsystem header for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * It gets better!
 */

#ifndef HookShoulder_H
#define HookShoulder_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class HookShoulder: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Victor 			*HookShoulderMotor;
	Potentiometer	*HookShoulderPot;//Pot refers to potentiometers
	PIDController	*HookShoulderPID;

public:

	HookShoulder();
	void InitDefaultCommand();
	void UpAndDown(double);
	void MoveToPosition(double);
//	void MoveToBumperPosition();
};

#endif
