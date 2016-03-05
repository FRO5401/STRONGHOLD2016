#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL
//ExampleSubsystem* CommandBase::examplesubsystem = NULL;
OI*			CommandBase::oi 			= NULL;
DriveBase* 	CommandBase::drivebase 		= NULL;//Makes the static null, or makes the static a clean slate, so nothing is moving yet
Feeder*		CommandBase::feeder			= NULL;
HookShoulder*	CommandBase::hookshoulder	= NULL;
OffboardCompressor*	CommandBase::offboardcompressor	= NULL;
Scale*		CommandBase::scale			= NULL;
Scimitar*	CommandBase::scimitar		= NULL;
Shooter* 	CommandBase::shooter		= NULL;
//ShortHook*	CommandBase::shorthook		= NULL;
SPT*		CommandBase::spt		= NULL;
WateryTart*	CommandBase::waterytart		= NULL;
RelaySys*	CommandBase::relaysys		= NULL;


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

	oi 					= new OI();
	drivebase 			= new DriveBase();//Connects the static to the subsystem
	feeder				= new Feeder();
	hookshoulder 		= new HookShoulder();
	offboardcompressor 	= new OffboardCompressor();
	scale				= new Scale();
	scimitar			= new Scimitar();
	shooter 			= new Shooter();
//	shorthook			= new ShortHook();
	spt					= new SPT();
	waterytart			= new WateryTart();
	relaysys	= new RelaySys();
}
