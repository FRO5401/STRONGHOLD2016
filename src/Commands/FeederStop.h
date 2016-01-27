#ifndef FeederStop_H
#define FeederStop_H

#include "../CommandBase.h"
#include "WPILib.h"

class FeederStop: public CommandBase
{
public:
	FeederStop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
