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
