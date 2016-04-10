#ifndef AutoDriveCommand_H
#define AutoDriveCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoDriveCommand: public CommandBase
{
public:
	float DesiredDistance;
	double AutoDriveSpeed;
	bool DoneTraveling;
	float DistanceTraveled;
	float heading;
	float drift;
	float kP_Drift;
	double Timeout;

//	AutoDriveCommand(float);
	AutoDriveCommand(float, double, double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
