#ifndef SPTMoveToPosition_H
#define SPTMoveToPosition_H

#include "../CommandBase.h"
#include "WPILib.h"

class SPTMoveToPosition: public CommandBase
{
private:
	bool finished;
	float DesiredAngle;
public:
	SPTMoveToPosition(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
