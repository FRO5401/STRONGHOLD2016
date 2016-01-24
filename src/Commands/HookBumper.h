#ifndef HookBumper_H
#define HookBumper_H

#include "../CommandBase.h"
#include "WPILib.h"

class HookBumper: public CommandBase
{
public:
	HookBumper();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
