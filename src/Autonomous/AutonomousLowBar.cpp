#include "Autonomous/AutonomousLowBar.h"
#include "Commands/AutoLaunch.h"
#include "Commands/HookShoulderMoveToPosition.h"
#include "Commands/SPTMoveToPosition.h"

#include "Autonomous/AutoHookScimitarOnBumper.h"
#include "Autonomous/AutoTurnAngleCommand.h"
#include "Autonomous/AutoDeliverBall.h"
#include "Autonomous/AutoDriveCommand.h"

//Includes are for commands that are used in this command group

const double SlowDriveSpeed = 0.35;
const double ObstacleSpeed = 0.4;
const double LowBarAutoDriveSpeed	= 0.65;
const double FullSpeed = 0.95;

AutonomousLowBar::AutonomousLowBar(int DefensePosition, int GoalPosition, int LowOrHigh)
{
	//SPT is in the front
	std::cout << "Starting Low Bar Autonomous Mode\n";

	std::cout << "Hooking scimitar onto bumper\n";
	AddParallel(new AutoHookScimitarOnBumper());
	std::cout << "Move SPT Down\n";
	AddParallel(new SPTMoveToPosition(-24.5));
	std::cout << "Drive to Defense\n";
	AddSequential(new AutoDriveCommand(25.0, SlowDriveSpeed, 15));

	std::cout << "Drive through defense\n";
	AddSequential(new AutoDriveCommand(48.0, ObstacleSpeed, 15));//Formerly -200 //Before Formerly -122.5 //TODO calibrate

	std::cout << " and further\n";
	AddSequential(new AutoDriveCommand(166.0, LowBarAutoDriveSpeed, 15));//Formerly -200 //Before Formerly -122.5 //Added 18 inches 4/28/16

	std::cout << "Turn to goal\n";
	AddSequential(new AutoTurnAngleCommand(57.5));//Original: 50; Adjusted for Curve: 60.5; Adjusted for missing off right to 55

	std::cout << "Move SPT up a bit to score\n";
	AddParallel(new SPTMoveToPosition(-10.5));
	std::cout << "Drive to goal\n";
	AddSequential(new AutoDriveCommand(80, FullSpeed, 15));//Was 80.0 inches, minus 3 inches at 041516 at 9:58

	std::cout << "Final Approach to goal\n";
	AddParallel(new AutoDriveCommand(5.0, 1, 15));
	std::cout << "Deliver ball out to goal\n";
	AddSequential(new AutoDeliverBall(2.0));

	std::cout << "Stopping Low Bar Autonomous Mode\n";
	//Drive onto batter (130?) and get SPT into position (check with drive team)

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
