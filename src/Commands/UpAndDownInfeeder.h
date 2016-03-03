#ifndef UpAndDownInfeeder_H
#define UpAndDownInfeeder_H

#include "../CommandBase.h"
#include "WPILib.h"

class UpAndDownInfeeder: public CommandBase
{
private:
	bool POVPress;
	int POV;

public:
	UpAndDownInfeeder();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SPTMoveToSetPoint(float);
};

#endif
