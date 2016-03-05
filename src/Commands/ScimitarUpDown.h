#ifndef ScimitarUpDown_H
#define ScimitarUpDown_H

#include "../CommandBase.h"
#include "WPILib.h"

class ScimitarUpDown: public CommandBase
{
private:
	int DpadDirection;
public:
	ScimitarUpDown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
