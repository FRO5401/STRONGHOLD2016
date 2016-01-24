#ifndef AbortReach_H
#define AbortReach_H

#include "../CommandBase.h"
#include "WPILib.h"

class AbortReach: public CommandBase
{
public:
	AbortReach();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
