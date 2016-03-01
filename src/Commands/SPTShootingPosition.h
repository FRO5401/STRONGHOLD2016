#ifndef SPTShootingPosition_H
#define SPTShootingPosition_H

#include "../CommandBase.h"
#include "WPILib.h"

class SPTShootingPosition: public CommandBase
{
public:
	SPTShootingPosition();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
