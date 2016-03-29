#ifndef AutoHookShoulderMove_H
#define AutoHookShoulderMove_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoHookShoulderMove: public CommandBase
{
private:
	bool IsFinished;

public:
	AutoHookShoulderMove(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
