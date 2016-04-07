#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

//Include headers for all subsystems
#include "OI.h"
#include "Subsystems/DriveBase.h"
#include "Subsystems/Feeder.h"
#include "Subsystems/HookShoulder.h"
#include "Subsystems/OffboardCompressor.h"
#include "Subsystems/Scale.h"
#include "Subsystems/Scimitar.h"
#include "Subsystems/Shooter.h"
//#include "Subsystems/ShortHook.h"
#include "Subsystems/SPT.h"
//#include "Subsystems/WateryTart.h"
#include "Subsystems/RelaySys.h"
#include <string>
#include "Commands/Command.h"
#include "WPILib.h"


/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */

class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static OI *oi;

	//Creates statics. I don't really understand it, but statics are like the virtual robot parts
	//Statics are manipulated to affect the physical robot
	//A static is necessary for each subsystem
	static DriveBase 		*drivebase;
	static Feeder 			*feeder;
	static HookShoulder 	*hookshoulder;
	static OffboardCompressor *offboardcompressor;
	static Scale 			*scale;
	static Scimitar 		*scimitar;
	static Shooter 			*shooter;
//	static ShortHook 		*shorthook;
	static SPT 				*spt;
//	static WateryTart 		*waterytart;
	static RelaySys 	*relaysys;
};

#endif
