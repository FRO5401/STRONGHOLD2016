/*
 * Catapult shooter subsystem for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 */


#ifndef SRC_SUBSYSTEMS_SHOOTER_H_
#define SRC_SUBSYSTEMS_SHOOTER_H_

#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "OI.h"

class Shooter: public Subsystem
{
//private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Victor *ShooterMotor;
	DigitalInput *ShooterSwitch;
	Encoder *ShooterEnc;

public:

	Shooter();
	void InitDefaultCommand();
	void Shoot();
	void Override(double);
};




#endif /* SRC_SUBSYSTEMS_SHOOTER_H_ */
