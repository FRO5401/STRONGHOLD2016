#ifndef FeedOutFromInner_H
#define FeedOutFromInner_H

#include "../CommandBase.h"
#include "WPILib.h"

class FeedOutFromInner: public CommandBase
{
public:
	FeedOutFromInner();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
