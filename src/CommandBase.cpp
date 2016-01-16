#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
//ExampleSubsystem* CommandBase::examplesubsystem = NULL;
OI* CommandBase::oi 				= NULL;
DriveBase *CommandBase::drivebase 	= NULL;//Makes the static null, or makes the static a clean slate, so nothing is moving yet

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
//	examplesubsystem = new ExampleSubsystem();

	oi = new OI();
	drivebase = new DriveBase();//Connects the static to the subsystem
}
