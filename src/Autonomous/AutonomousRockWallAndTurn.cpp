#include "Autonomous/AutonomousRockWallAndTurn.h"
#include "Autonomous/AutonomousRockWall.h"
#include "Autonomous/AutoTurnAngleCommand.h"
#include "Autonomous/AutoDriveCommand.h"

const double RockWallAndTurnAutoDriveSpeed	= 0.85;
const int NotUsed = 0; //for unused parameters of rockwall originally for switch statements

AutonomousRockWallAndTurn::AutonomousRockWallAndTurn()
{
	AddSequential(new AutonomousRockWall(NotUsed, NotUsed, NotUsed));
//	AddSequential(new AutoDriveCommand(-12,RockWallAndTurnAutoDriveSpeed, 15));//Not needed
	AddSequential(new AutoTurnAngleCommand(180));
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
