#ifndef InfeederLiftIntoInfeederPosition_H
#define InfeederLiftIntoInfeederPosition_H

#include "../CommandBase.h"
#include "WPILib.h"

class InfeederLiftIntoInfeederPosition: public CommandBase
{
public:
	InfeederLiftIntoInfeederPosition();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
