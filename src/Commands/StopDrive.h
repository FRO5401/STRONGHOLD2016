#ifndef StopDrive_H
#define StopDrive_H

#include "../CommandBase.h"
#include "WPILib.h"

class StopDrive: public CommandBase
{
public:
	StopDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
