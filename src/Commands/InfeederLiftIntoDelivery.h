#ifndef InfeederLiftIntoDelivery_H
#define InfeederLiftIntoDelivery_H

#include "../CommandBase.h"
#include "WPILib.h"

class InfeederLiftIntoDelivery: public CommandBase
{
public:
	InfeederLiftIntoDelivery();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
