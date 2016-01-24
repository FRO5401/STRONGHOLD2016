#ifndef ReachForBar_H
#define ReachForBar_H

#include "../CommandBase.h"
#include "WPILib.h"

class ReachForBar: public CommandBase
{
public:
	ReachForBar();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
