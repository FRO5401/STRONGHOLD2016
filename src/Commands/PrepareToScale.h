#ifndef PrepareToScale_H
#define PrepareToScale_H

#include "../CommandBase.h"
#include "WPILib.h"

class PrepareToScale: public CommandBase
{
public:
	PrepareToScale();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
