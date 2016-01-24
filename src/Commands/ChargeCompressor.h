#ifndef ChargeCompressor_H
#define ChargeCompressor_H

#include "../CommandBase.h"
#include "WPILib.h"

class ChargeCompressor: public CommandBase
{
public:
	ChargeCompressor();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
