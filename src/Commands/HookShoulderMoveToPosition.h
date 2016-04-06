#ifndef HookShoulderMoveToPosition_H
#define HookShoulderMoveToPosition_H

#include "../CommandBase.h"
#include "WPILib.h"

class HookShoulderMoveToPosition: public CommandBase
{
public:
	bool finishedHookShoulder;
	double DesiredAngleHookShoulder;

	HookShoulderMoveToPosition(double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
