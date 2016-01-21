/*
 * XboxMove.h
 *
 *  Created on: Jan 13, 2016
 *      Author: FROGramming Team
 */

//#ifndef SRC_COMMANDS_XBOXMOVE_H_
//#define SRC_COMMANDS_XBOXMOVE_H_

#ifndef XboxMove_H
#define XboxMove_H

#include "../CommandBase.h"
//#include "WPILib.h"

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

#endif



//#endif /* SRC_COMMANDS_XBOXMOVE_H_ */
