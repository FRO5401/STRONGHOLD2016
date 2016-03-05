#ifndef AutoDoNothing_H
#define AutoDoNothing_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoDoNothing: public CommandBase
{
public:
	AutoDoNothing();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
