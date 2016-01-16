#ifndef SPT_H
#define SPT_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class SPT: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Victor *SPTShoulderMotor;

	SPT();
	void InitDefaultCommand();
	void UpAndDown(double);
	void MoveToDeliveryPosition();
	void MoveToInfeederPosition();
};

#endif
