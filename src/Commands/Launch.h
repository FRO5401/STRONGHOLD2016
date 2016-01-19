/*
 /*
 * Catapult launch command header for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 */
#ifndef SRC_COMMANDS_LAUNCH_H_
#define SRC_COMMANDS_LAUNCH_H_

#include "../CommandBase.h"
#include "WPILib.h"

class Launch: public CommandBase
{
public:
	Launch();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};
#endif

