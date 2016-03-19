#include "Autonomous/AutonomousRockWall.h"
#include "Autonomous/AutoDriveCommand.h"

#include "HookShoulderMoveToPosition.h"
#include "SPTMoveToPosition.h"

AutonomousRockWall::AutonomousRockWall(int DefensePosition, int GoalPosition, int LowOrHigh)
{
	//Measurements are based on theoretical calculations, physical test are needed
	//SPT starts from behind
	AddParallel(new HookShoulderMoveToPosition(45));//TODO Change Position with calibration, down
	AddParallel(new SPTMoveToPosition(192));//TODO edit this to be down to horizontal
	AddSequential(new AutoDriveCommand(97));//TODO Physically determine distance

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
