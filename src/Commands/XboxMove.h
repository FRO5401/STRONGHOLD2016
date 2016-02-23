/*
 * Drive command header for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * Kante is MVP
 */

#ifndef SRC_COMMANDS_XBOXMOVE_H_
#define SRC_COMMANDS_XBOXMOVE_H_

#include "../CommandBase.h"
#include "WPILib.h"

class XboxMove: public CommandBase
{
private:
	float distance;
public:
	XboxMove();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};


#endif /* SRC_COMMANDS_XBOXMOVE_H_ */
