#ifndef HookShoulderMoveToPosition_H
#define HookShoulderMoveToPosition_H

#include "../CommandBase.h"
#include "WPILib.h"

class HookShoulderMoveToPosition: public CommandBase
{
public:
	bool finishedHookShoulder;
	double DesiredAngleHookShoulder;
	double Timeout;

	HookShoulderMoveToPosition(double);
	HookShoulderMoveToPosition(double, double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
