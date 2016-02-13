#ifndef DrivingWithEncoderInput_H
#define DrivingWithEncoderInput_H

#include "../CommandBase.h"
#include "WPILib.h"

class DrivingWithEncoderInput: public CommandBase
{
public:
	DrivingWithEncoderInput();
	void Initialize(double);
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
