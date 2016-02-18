#ifndef SPT_H
#define SPT_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class SPT: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Victor *SPTShoulderMotor;
	PIDController *SPTPotPID;//
	Potentiometer *SPTPot;//Pot refers to potentiometers
	double MotorOutput;

	//PID Values
	double SPT_Kp 		= 0;//Proportional - how far away - distance
	double SPT_Ki		= 0 ;//Integral - how long traveled - time
	double SPT_Kd		= 0;//Derivative - how fast getting there - speed

public:

	SPT();
	void InitDefaultCommand();
	void UpAndDown(double);
	void MoveToDeliveryPosition();
	void MoveToInfeederPosition();
	void ClearShooterPathPosition();
};

#endif
