#ifndef SPTMoveToPosition_H
#define SPTMoveToPosition_H

#include "../CommandBase.h"
#include "WPILib.h"

class SPTMoveToPosition: public CommandBase
{
private:
	bool finished;
	float DesiredAngle;
	float Timeout;

public:
	SPTMoveToPosition(float);
	SPTMoveToPosition(float,float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
