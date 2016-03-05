#ifndef ShooterStop_H
#define ShooterStop_H

#include "../CommandBase.h"
#include "WPILib.h"

class ShooterStop: public CommandBase
{
public:
	ShooterStop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
