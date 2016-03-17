#ifndef SPTMove_H
#define SPTMove_H

#include "../CommandBase.h"
#include "WPILib.h"

class SPTMove: public CommandBase
{
public:
	SPTMove();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
