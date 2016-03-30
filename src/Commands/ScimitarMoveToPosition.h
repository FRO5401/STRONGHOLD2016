#ifndef ScimitarMoveToPosition_H
#define ScimitarMoveToPosition_H

#include "../CommandBase.h"
#include "WPILib.h"

class ScimitarMoveToPosition: public CommandBase
{
private:
	bool Finished;
	double DesiredPosition;
	double CurrentPosition;

public:
	ScimitarMoveToPosition(double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
