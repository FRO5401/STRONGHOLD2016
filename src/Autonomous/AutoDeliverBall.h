#ifndef AutoDeliverBall_H
#define AutoDeliverBall_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoDeliverBall: public CommandBase
{
private:
	float FeedTime;
public:
	AutoDeliverBall(float);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
