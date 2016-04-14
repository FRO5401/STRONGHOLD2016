#include "Autonomous/AutonomousPortcullis.h"
#include "Autonomous/AutoHookScimitarOnBumper.h"
#include "Commands/SPTMoveToPosition.h"
#include "Autonomous/AutoDriveCommand.h"

const double PortcullisAutoDriveSpeed = .85;

AutonomousPortcullis::AutonomousPortcullis(int DefensePosition, int GoalPosition, int LowOrHigh)
{
	AddParallel(new AutoHookScimitarOnBumper());
	AddSequential(new SPTMoveToPosition(-17)); //Move SPT down to prepare to drive over cheval, does not need to move up
	AddSequential(new AutoDriveCommand(140, PortcullisAutoDriveSpeed, 15)); //Drive to defense //TODO edit
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

