/*

 * Drive command for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 */

#ifndef XBOXMOVE_H
#define XBOXMOVE_H

#include "../CommandBase.h"
//#include "CommandBase.h"
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

#endif //XBOXMOVE_H
