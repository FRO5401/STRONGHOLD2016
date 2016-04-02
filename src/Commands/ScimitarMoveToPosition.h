#ifndef ScimitarMoveToPosition_H
#define ScimitarMoveToPosition_H

#include "../CommandBase.h"
#include "WPILib.h"

class ScimitarMoveToPosition: public CommandBase
{
private:
	bool Finished;
//	double DesiredRight;
//	double DesiredLeft;
	double DesiredDistance;
	double RightPosition;
	double LeftPosition;
	double Left;
	double Right;
	double error;
	double RightEncRaw;
	double LeftEncRaw;
	bool Override;
	bool LeftClose;
	bool LeftFar;
	bool RightClose;
	bool RightFar;

public:
	ScimitarMoveToPosition(double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
