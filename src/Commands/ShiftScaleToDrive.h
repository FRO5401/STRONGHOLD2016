#ifndef ShiftScaleToDrive_H
#define ShiftScaleToDrive_H

#include "../CommandBase.h"
#include "WPILib.h"

class ShiftScaleToDrive: public CommandBase
{
public:
	ShiftScaleToDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
