#include "Autonomous/AutonomousMoat.h"

#include "Autonomous/AutoDriveCommand.h"
#include "Autonomous/AutoHookScimitarOnBumper.h"
const double AutoDriveSpeed	= 0.95; //.4 for inital lowbar

AutonomousMoat::AutonomousMoat(int DefensePosition, int GoalPosition, int LowOrHigh)
{
	AddSequential(new AutoHookScimitarOnBumper());
	AddSequential(new AutoDriveCommand(-200, AutoDriveSpeed, 15));//TODO Physically determine distance
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
