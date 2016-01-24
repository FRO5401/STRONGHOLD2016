/*
 * Drive command header for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 */

#ifndef SRC_COMMANDS_XBOXMOVE_H_
#define SRC_COMMANDS_XBOXMOVE_H_

#include "../CommandBase.h"
#include "WPILib.h"

class XboxMove: public CommandBase
{
public:
	XboxMove();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


#endif /* SRC_COMMANDS_XBOXMOVE_H_ */
