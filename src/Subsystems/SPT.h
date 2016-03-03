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
	//Encoder *SPTEnc;
	Potentiometer *SPTPot;
	double MotorOutput;

public:

	SPT();
	void InitDefaultCommand();
	void UpAndDown(double, bool);
	void MoveToDeliveryPosition();
	void MoveToInfeederPosition();
	void ClearShooterPathPosition();
	void StopForShoot();
	float GetAdjustedEncDistance();
	void Reset();
};

#endif
