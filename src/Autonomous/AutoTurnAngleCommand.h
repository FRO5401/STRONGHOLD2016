#ifndef AutoTurnAngleCommand_H
#define AutoTurnAngleCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoTurnAngleCommand: public CommandBase
{
private:
	float DesiredTurnAngle;
	float CurrentAngle;
	float InitAngle;
	bool Finished;
public:
	AutoTurnAngleCommand(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
