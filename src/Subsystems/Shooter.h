/*
 * Shooter.h
 *
 *  Created on: Jan 16, 2016
 *      Author: AFRO
 */

#ifndef SRC_SUBSYSTEMS_SHOOTER_H_
#define SRC_SUBSYSTEMS_SHOOTER_H_

class Shooter: public Subsystem
{
//private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Victor *ShooterMotor;
	Encoder *ShooterEncoder;
	PIDController *ShooterPID;

public:

	Shooter();
	void InitDefaultCommand();
	void Shoot();
	void Override(double);
};




#endif /* SRC_SUBSYSTEMS_SHOOTER_H_ */
