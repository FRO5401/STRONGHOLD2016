#ifndef AutoTurnToAngleCommand_H
#define AutoTurnToAngleCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoTurnToAngleCommand: public CommandBase
{
public:
	float AngleToTurn;

	AutoTurnToAngleCommand(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

