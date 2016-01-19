/*
 * XboxMove.h
 *
 *  Created on: Jan 18, 2016
 *      Author: AFRO
 */

#ifndef SRC_COMMANDS_XBOXMOVE_H_
#define SRC_COMMANDS_XBOXMOVE_H_

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


#endif /* SRC_COMMANDS_XBOXMOVE_H_ */
