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
	 *					//Turn Left 90 degrees.
	 *					//Drive
	 *						break;
	 *					case 2:
	 *						break;
	 *					case 3:
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
