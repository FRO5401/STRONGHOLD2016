#ifndef StopDriveForAutonomous_H
#define StopDriveForAutonomous_H

#include "../CommandBase.h"
#include "WPILib.h"

class StopDriveForAutonomous: public CommandBase
{
public:
	StopDriveForAutonomous();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
