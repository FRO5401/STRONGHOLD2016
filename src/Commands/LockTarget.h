/*
 * Catapult shooter for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 */

#ifndef SRC_COMMANDS_LOCKTARGET_H_
#define SRC_COMMANDS_LOCKTARGET_H_


#include "../CommandBase.h"
#include "WPILib.h"

class LockTarget: public CommandBase
{
private:
	Range RING_HUE_RANGE;// = {0	, 96};	//Default hue range for ring light R
	Range RING_SAT_RANGE;// = {110	, 255};	//Default saturation range for ring light G
	Range RING_VAL_RANGE;// = {110	, 255};	//Default value range for ring light B
	float Area;
	float Aspect;
	float ImgLatency;
public:
	LockTarget();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
//#endif

#endif /* SRC_COMMANDS_LOCKTARGET_H_ */
