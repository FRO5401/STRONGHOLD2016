#ifndef HookShoulderUpDown_H
#define HookShoulderUpDown_H

#include "../CommandBase.h"
#include "WPILib.h"

class HookShoulderUpDown: public CommandBase
{
private:
	int DpadDirection;
	bool Override;
	double CurrentPosition;
	double HookShoulderMove;
public:
	HookShoulderUpDown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
