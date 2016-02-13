#include "Autonomous/AutonomousLowBar.h"

AutonomousLowBar::AutonomousLowBar(int HighGoalPosition, int DefensePosition)
{
	AddSequential(new DrivingWithEncoderInput());
	//Adjust Angle COMMAND NOT CREATED YET
	AddSequential(new LockTarget());//LockTarget needs it to be edited to find if it is within range

	AddSequential(new Launch());

/*	Pusedocode
 * 	EncoderDrive() No parameter necessary. The placement will be the DistanceForEncoderDrive in DriveBase. COMMAND MADE
 * 	AdjustAngle(0) Adjusts angle to 0 to make it run straight. COMMAND NOT CREATED YET
 *	AutoTurn(45) Turns 45 degrees. VALUE MAY CHANGE. COMMAND NOT CREATED YET. May have parameters or might be like DistanceForEncoderDrive for EncoderDrive
 *	AutoTarget() Finds target and locks on. Might be split into two command group. NEEDS EDITS
 *	Launch() COMMAND MADE
 *
 */


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
