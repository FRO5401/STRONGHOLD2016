#ifndef MoveSPTtoPosition_H
#define MoveSPTtoPosition_H

#include "../CommandBase.h"
#include "WPILib.h"

class MoveSPTtoPosition: public CommandBase
{
private:
	bool finished;
	float DesiredAngle;
public:
	MoveSPTtoPosition(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
