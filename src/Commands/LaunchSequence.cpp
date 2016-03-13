#include "LaunchSequence.h"
#include "Launch.h"
#include "SPTShootingPosition.h"
#include "ShooterReset.h"

const double ShooterResetDwell	= 1;

LaunchSequence::LaunchSequence()
{
	std::cout << ("Starting launch sequence\n");  // @REVIEW NJL: This runs at robot boot time.  AddSequential is just a registration.  Don't expect cout text to appear during normal execution as you are proceeding through the sequence, because this code will not be running at that time.  The command sequence will be iterating through these registered commands.

	AddSequential (new SPTShootingPosition());
	std::cout << ("Starting launch\n");
	AddSequential (new Launch());
//	Wait(ShooterResetDwell);  // @REVIEW NJL: If you need a delay in the sequence, you'll need to write a delay command.  Do nothing in execute, and return true from IsFinished once the delay time has elapsed.
	std::cout << ("Starting reset\n");
	AddSequential (new ShooterReset());

	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
