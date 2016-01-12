#ifndef XboxDriving_H
#define XboxDriving_H

#include "../CommandBase.h"
#include "WPILib.h"

class XboxDriving: public CommandBase
{
public:
	XboxDriving();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
