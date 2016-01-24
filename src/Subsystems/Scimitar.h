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
	Victor *Lobber;	//Variable for motor to extend the scimitar to scale the tower

public:
	Scimitar();
	void InitDefaultCommand();
	void Extend(bool);
};

#endif
