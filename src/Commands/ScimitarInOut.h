#ifndef ScimitarInOut_H
#define ScimitarInOut_H

#include "../CommandBase.h"
#include "WPILib.h"

class ScimitarInOut: public CommandBase
{
private:
	float LeftEncoderDist;
	float RightEncoderDist;
	int LeftEncoderRaw;
	int RightEncoderRaw;
	double Left;
	double Right;
	double K;
	double Input;
	bool Override;
	int error;
	bool RightFarLimit_Cmd;
	bool RightCloseLimit_Cmd;
	bool LeftFarLimit_Cmd;
	bool LeftCloseLimit_Cmd;

public:
	ScimitarInOut();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
