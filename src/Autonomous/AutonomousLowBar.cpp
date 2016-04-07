#include "Autonomous/AutonomousLowBar.h"
#include "Commands/AutoLaunch.h"
#include "Commands/HookShoulderMoveToPosition.h"
#include "Commands/SPTMoveToPosition.h"

#include "Autonomous/AutoHookScimitarOnBumper.h"
#include "Autonomous/AutoTurnAngleCommand.h"
#include "Autonomous/AutoTurnToAngleCommand.h"
#include "Autonomous/AutoDeliverBall.h"
#include "Autonomous/AutoDriveCommand.h"

//Includes are for commands that are used in this command group

AutonomousLowBar::AutonomousLowBar(int DefensePosition, int GoalPosition, int LowOrHigh)
{
	//SPT is in the back
//	AddParallel(new AutoHookScimitarOnBumper()); //Scimitar is not currently on the robot
	AddParallel(new SPTMoveToPosition(-24.0));
	AddSequential(new AutoDriveCommand(-15.0));
	AddSequential(new WaitCommand(3));
	AddSequential(new AutoDriveCommand(-125.0));//Formerly -200 //Before Formerly -122.5 //TODO calibrate
	//Drive to good distance
	AddSequential(new AutoTurnToAngleCommand(50));
	//Drive onto batter (130?) and get SPT into position (check with drive team)
	AddSequential(new AutoDeliverBall(2.0));

//	AddSequential(new SPTMoveToPosition(90));
//	AddSequential(new AutoTurnAngleCommand(38));//46.8 but we overshoot
//	AddSequential(new AutoDeliverBall(2.0));
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
