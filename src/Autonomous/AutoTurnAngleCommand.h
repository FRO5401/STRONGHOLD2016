#ifndef AutoTurnAngleCommand_H
#define AutoTurnAngleCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoTurnAngleCommand: public CommandBase
{
private:
	float Angle;
public:
	AutoTurnAngleCommand(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
