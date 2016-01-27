#ifndef FeedInFromInner_H
#define FeedInFromInner_H

#include "../CommandBase.h"
#include "WPILib.h"

class FeedInFromInner: public CommandBase
{
public:
	FeedInFromInner();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
