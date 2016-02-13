#ifndef RelayOn_H
#define RelayOn_H

#include "../CommandBase.h"
#include "WPILib.h"

class RelayOn: public CommandBase
{
public:
	RelayOn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
