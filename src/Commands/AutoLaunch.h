/*
 * Catapult shooter for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 */

#ifndef SRC_COMMANDS_AutoLaunch_H_
#define SRC_COMMANDS_AutoLaunch_H_


#include "../CommandBase.h"
#include "WPILib.h"

class AutoLaunch: public CommandBase
{
private:
	Range RING_HUE_RANGE;// = {0	, 96};	//Default hue range for ring light R
	Range RING_SAT_RANGE;// = {110	, 255};	//Default saturation range for ring light G
	Range RING_VAL_RANGE;// = {110	, 255};	//Default value range for ring light B
	float Area;
	float Aspect;
	float ImgLatency;
	double Angle;
	double AngleRange;
	bool Finish;
public:
	AutoLaunch();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
//#endif

#endif /* SRC_COMMANDS_AutoLaunch_H_ */
