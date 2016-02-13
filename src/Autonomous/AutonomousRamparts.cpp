#include "Autonomous/AutonomousRamparts.h"

AutonomousRamparts::AutonomousRamparts(int DefensePosition, int GoalPosition, int LowOrHigh)
{
	/* Pseudocode
	 * EncoderDrive() Needs a value for DistanceForEncoderDrive
	 * AdjustAngle to 0.
	 * if(GoalPosition == 1)
	 * {
	 * 		switch(DefensePosition)
	 * 		{
	 * 			case 2:
	 * 				switch(GoalPosition)
	 * 				{
	 *					case 1:
	 *						//Turn Left 90 degrees.
	 *						//EncoderDrive(some inches)
	 *						//Adjust angle
	 *						//Turn Right 90 deg
	 *						//EncoderDrive(some inches)
	 *						//Adjust angle
	 *						//Turn 45 Right
	 *						//LockTarget
	 *						//Launch
	 *						break;
	 *					case 2:
	 *						//Turn right 90 degrees
	 *						//EncoderDrive(some inches)
	 *						//Adjust angle
	 *						//Turn Left 90 degrees
	 *						//EncoderDrive(some inches)
	 *						//AutoTarget
	 *						//Launch
	 *						break;
	 *					case 3:
	 *						////Turn right 90 degrees
	 *						//EncoderDrive(some inches)
	 *						//Adjust angle
	 *						//Turn Left 90 degrees
	 *						//EncoderDrive(some inches)
	 *						//Adjust angle
	 *						//Turn left by 45 degrees
	 *						//AutoTarget
	 *						//Launch
	 *						break;
	 * 				}
	 * 				break;
	 * 			case 3:
	 * 				switch(GoalPosition)
	 * 				{
	 *
	 * 				}
	 * 				break;
	 * 			case 4:
	 * 				switch(GoalPosition)
	 * 				{
	 *
	 * 				}
	 * 				break;
	 * 			case 5:
	 * 				switch(GoalPosition)
	 * 				{
	 *
	 * 				}
	 * 				break;
	 * 		}
	 * }
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
