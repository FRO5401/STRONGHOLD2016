#ifndef XboxDrivingSkid_H
#define XboxDrivingSkid_H

#include "../CommandBase.h"
#include "WPILib.h"

class XboxDrivingSkid: public CommandBase
{
public:
	XboxDrivingSkid();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
