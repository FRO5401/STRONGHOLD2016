/*
 * Offboard Compressor subsystem for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * In order to maintain air-speed velocity, a swallow needs to beat its wings
 * forty-three times every second, right?
 */


#include "OffboardCompressor.h"
#include "../RobotMap.h"

OffboardCompressor::OffboardCompressor() :
		Subsystem("OffboardCompressor")
{
	MainCompressor	=	new Compressor();

}

void OffboardCompressor::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void OffboardCompressor::CompressorOn(){
	MainCompressor -> Start();//Starts compressor.
	//The SetClosedLoopControl(true) can also be used instead
}

void OffboardCompressor::CompressorOff(){
	MainCompressor -> Stop();//Stops compressor.
	//The SetClosedLoopControl(false) can also be used instead
}

