#ifndef Feeder_H
#define Feeder_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Feeder: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	Victor *FeederOuterFasterMotor;
	Victor *FeederInnerSlowerMotor;

	Feeder();
	void InitDefaultCommand();
	void FeedInFromField();
	void FeedOutToField();
	void FeedToShooter();
	void FeedOutFromShooter();
	void StopFeed();
	void FeedOutToGoal();

};

#endif
