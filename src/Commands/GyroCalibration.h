#ifndef GyroCalibration_H
#define GyroCalibration_H

#include "../CommandBase.h"
#include "WPILib.h"

class GyroCalibration: public CommandBase
{
private:
	DriverStation* DS;

public:
	GyroCalibration();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
