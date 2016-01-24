#ifndef Scale_H
#define Scale_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Scale: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DoubleSolenoid* ScaleEngage;
	DoubleSolenoid* DriveDisengage;

public:
	Scale();
	void InitDefaultCommand();
	void EngageScaleMode();
	void DisengageScaleMode();
};

#endif
