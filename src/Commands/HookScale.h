#ifndef HookScale_H
#define HookScale_H

#include "../CommandBase.h"
#include "WPILib.h"

class HookScale: public CommandBase
{
public:
	HookScale();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
