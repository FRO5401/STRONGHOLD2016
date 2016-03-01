#ifndef AutonomousAutoTurnAngle_H
#define AutonomousAutoTurnAngle_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonomousAutoTurnAngle: public CommandBase
{
private:
	float Angle;
public:
	AutonomousAutoTurnAngle(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
