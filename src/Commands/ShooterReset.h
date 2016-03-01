#ifndef ShooterReset_H
#define ShooterReset_H

#include "../CommandBase.h"
#include "WPILib.h"

class ShooterReset: public CommandBase
{
private:
	bool ResetComplete;
public:
	ShooterReset();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
