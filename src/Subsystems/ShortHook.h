/*
 * Drive Base subsystem for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * Its a question of mass ratio
 */

#ifndef ShortHook_H
#define ShortHook_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ShortHook: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DoubleSolenoid* ShortHookExtend;

public:
	ShortHook();
	void InitDefaultCommand();
	void Extend(bool);
};

#endif
