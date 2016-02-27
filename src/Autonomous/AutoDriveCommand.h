#ifndef AutoDriveCommand_H
#define AutoDriveCommand_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutoDriveCommand: public CommandBase
{
public:
	AutoDriveCommand();
	void Initialize(float);
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
