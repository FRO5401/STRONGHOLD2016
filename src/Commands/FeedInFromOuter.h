#ifndef FeedInFromOuter_H
#define FeedInFromOuter_H

#include "../CommandBase.h"
#include "WPILib.h"

class FeedInFromOuter: public CommandBase
{
public:
	FeedInFromOuter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
