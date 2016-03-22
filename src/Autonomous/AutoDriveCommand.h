#ifndef AutoDriveCommand_H
#define AutoDriveCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoDriveCommand: public CommandBase
{
public:
	float DesiredDistance;
	bool DoneTraveling;
	float DistanceTraveled;
	float heading;
	float drift;

	AutoDriveCommand(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
