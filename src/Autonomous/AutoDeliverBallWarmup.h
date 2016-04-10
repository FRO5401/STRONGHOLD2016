#ifndef AutoDeliverBallWarmup_H
#define AutoDeliverBallWarmup_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoDeliverBallWarmup: public CommandBase
{
private:
	float FeedTime;
public:
	AutoDeliverBallWarmup(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
