/*
 * Catapult shooter for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 */

#ifndef SRC_COMMANDS_TARGET_H_
#define SRC_COMMANDS_TARGET_H_


#include "../CommandBase.h"
#include "WPILib.h"

class Target: public CommandBase
{
public:
	Target();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
//#endif

#endif /* SRC_COMMANDS_TARGET_H_ */
