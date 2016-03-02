#include "Autonomous/AutonomousLowBar.h"
#include "Commands/AutoLaunch.h"
#include "Commands/InfeederLiftIntoDelivery.h"
#include "Commands/InfeederLiftIntoInfeederPosition.h"

#include "Autonomous/AutonomousAutoTurnAngle.h"
#include "Autonomous/AutoDeliverBall.h"
#include "Autonomous/AutoDriveCommand.h"
//Includes are for commands that are used in this command group

AutonomousLowBar::AutonomousLowBar(int DefensePosition, int GoalPosition, int LowOrHigh)
{
/*	AddSequential(new DrivingWithEncoderInput());
	//Adjust Angle COMMAND NOT CREATED YET
	AddSequential(new LockTarget());//LockTarget needs it to be edited to find if it is within range

	AddSequential(new Launch());
*/

/*	Pusedocode
 *	AddSequential(new AutoTurnToAngle(180); //Because SPT is not need thus immediate position for shooting can work
 *	AddSequential(new AutoDriveCommand(#));
 *	AddSequential(new AutoTurnToAngleCommand(45)); maybe????
 *	AddSequential(new AutoLaunch());
 *
 */
//	Not needed because the driver will position the robot as necessary before turning on
//	AddSequential(new AutoTurnToAngleCommand(180); //Because SPT is not need thus immediate position for shooting can work

	AddSequential(new InfeederLiftIntoInfeederPosition());
	AddSequential(new AutoDriveCommand(-215));//Formerly -122.5
	Wait(.5);
	AddSequential(new InfeederLiftIntoDelivery());
	AddSequential(new AutonomousAutoTurnAngle(37));//46.8 but we overshoot
	AddSequential(new AutoDeliverBall(2.0));
	AddSequential(new AutoLaunch());


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
