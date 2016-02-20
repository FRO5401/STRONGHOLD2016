#ifndef RelaySys_H
#define RelaySys_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class RelaySys: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Relay *LightRing;
	Relay *CarriageLights;
public:
	RelaySys();
	void InitDefaultCommand();
	void TurnOn();
	void TurnOff();
	void ShootLights();
};

#endif
