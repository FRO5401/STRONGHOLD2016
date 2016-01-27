#ifndef FeedOutFromOuter_H
#define FeedOutFromOuter_H

#include "../CommandBase.h"
#include "WPILib.h"

class FeedOutFromOuter: public CommandBase
{
public:
	FeedOutFromOuter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
