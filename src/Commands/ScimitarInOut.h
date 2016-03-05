#ifndef ScimitarInOut_H
#define ScimitarInOut_H

#include "../CommandBase.h"
#include "WPILib.h"

class ScimitarInOut: public CommandBase
{
public:
	ScimitarInOut();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
