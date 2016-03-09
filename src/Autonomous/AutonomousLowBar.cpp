#include "Autonomous/AutonomousLowBar.h"
#include "Commands/AutoLaunch.h"
#include "Commands/MoveSPTtoPosition.h"

#include "Autonomous/AutoTurnAngleCommand.h"
#include "Autonomous/AutoDeliverBall.h"
#include "Autonomous/AutoDriveCommand.h"
//Includes are for commands that are used in this command group

AutonomousLowBar::AutonomousLowBar(int DefensePosition, int GoalPosition, int LowOrHigh)
{
	AddParallel(new MoveSPTtoPosition(192));
	AddSequential(new AutoDriveCommand(-15));
	AddSequential(new AutoDriveCommand(-200));//Formerly -122.5
	AddSequential(new MoveSPTtoPosition(90));
	AddSequential(new AutoTurnAngleCommand(38));//46.8 but we overshoot
	AddSequential(new AutoDeliverBall(2.0));
//	AddSequential(new AutoLaunch());

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
