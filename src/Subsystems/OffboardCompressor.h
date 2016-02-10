#ifndef OffboardCompressor_H
#define OffboardCompressor_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class OffboardCompressor: public Subsystem
{
private:
	Compressor* MainCompressor;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	OffboardCompressor();
	void InitDefaultCommand();
	void CompressorOn();
	void CompressorOff();
};

#endif
