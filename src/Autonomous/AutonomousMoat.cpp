#include "Autonomous/AutonomousMoat.h"

AutonomousMoat::AutonomousMoat(int DefensePosition, int GoalPosition, int LowOrHigh)
{
	/*	PsuedoCode V. 2.0
	 * 	AdjustAngle() so it's straight
	 * 	AutoDrive()
	 * 	SPT down under horizon
	 * 	AutoDrive()
	 * 	SPT up to horizontal
	 * 	AutoDrive()
	 * 	SPT down under horizon
	 * 	AutoDrive()
	 * 	SPT up to horizontal
	 * 	AutoDrive()
	 * 	AdjustAngle() so it's straight
	 * 	switch(DefensePosition)
	 * 	{
	 * 		case 2:
	 * 			switch(GoalPosition)
	 * 			{
	 * 				case 1:
	 * 					AutoTurn() left 90
	 * 					AutoDrive()
	 * 					AdjustAngle straight
	 * 					AutoTurn() right 90
	 * 					AutoDrive() up to appropriate distance from goal
	 * 					AdjustAngle straight
	 * 					AutoTutn() turns directly towards goal
	 * 					switch(LowOrHigh)
	 * 					{
	 * 						case 1:
	 * 							AutoDrive(); To front of low goal
	 * 							OutFeed(); AKA low kick
	 * 							break;
	 * 						case 2:
	 * 						//Maybe loop between AutoDrive and AutoTarget
	 * 							AutoTarget();
	 * 							Shoot();
	 * 							break;
	 * 					}
	 * 					break;
	 * 				case 2:
	 * 					AutoTurn() Right 90
	 * 					AutoDrive()
	 * 					AdjustAngle straight
	 * 					AutoTurn() Left 90
	 * 					AutoDrive() up to appropriate distance from goal
	 * 					//Maybe loop between AutoDrive and AutoTarget
	 * 					AutoTarget();
	 * 					Shoot();
	 * 					break;
	 * 					}
	 * 					break;
	 * 				case 3:
	 * 					AutoTurn() Right 90
	 * 					AutoDrive() until it goes over the secret passage boundary
	 * 					AdjustAngle straight for after going over boundary
	 * 					AutoDrive() for the rest of the distance after boundary
	 * 					AdjustAngle() Make sure it's straight
	 * 					AutoTurn() Left 90
	 * 					AutoDrive() up to appropriate distance from goal
	 * 					AutoTurn() turns towards goal
	 * 					switch(LowOrHigh)
	 * 					{
	 * 						case 1:
	 * 							AutoDrive(); To In front of goal
	 * 							OutFeed(); AKA low kick
	 * 							break;
	 * 						case 2:
	 * 						//Maybe loop between AutoDrive and AutoTarget
	 * 							AutoTarget();
	 * 							Shoot();
	 * 							break;
	 * 					}
	 * 					break;
	 * 			}
	 * 			break;
	 * 		case 3:
	 * 			switch(GoalPosition)
	 * 			{
	 * 				case 1:
	 * 					AutoTurn() left 90
	 * 					AutoDrive()
	 * 					AdjustAngle straight
	 * 					AutoTurn() right 90
	 * 					AutoDrive() up to appropriate distance from goal
	 * 					AdjustAngle straight
	 * 					AutoTutn() turns directly towards goal
	 * 					switch(LowOrHigh)
	 * 					{
	 * 						case 1:
	 * 							AutoDrive(); To front of low goal
	 * 							OutFeed(); AKA low kick
	 * 							break;
	 * 						case 2:
	 * 						//Maybe loop between AutoDrive and AutoTarget
	 * 							AutoTarget();
	 * 							Shoot();
	 * 							break;
	 * 					}
	 * 					break;
	 * 				case 2:
	 * 					AutoTurn() Right 90
	 * 					AutoDrive()
	 * 					AdjustAngle straight
	 * 					AutoTurn() Left 90
	 * 					AutoDrive() up to appropriate distance from goal
	 * 					//Maybe loop between AutoDrive and AutoTarget
	 * 					AutoTarget();
	 * 					Shoot();
	 * 					break;
	 * 				case 3:
	 * 					AutoTurn() Right 90
	 * 					AutoDrive() until it goes over the secret passage boundary
	 * 					AdjustAngle straight for after going over boundary
	 * 					AutoDrive() for the rest of the distance after boundary
	 * 					AdjustAngle() Make sure it's straight
	 * 					AutoTurn() Left 90
	 * 					AutoDrive() up to appropriate distance from goal
	 * 					AutoTurn() turns towards goal
	 * 					switch(LowOrHigh)
	 * 					{
	 * 						case 1:
	 * 							AutoDrive(); To In front of goal
	 * 							OutFeed(); AKA low kick
	 * 							break;
	 * 						case 2:
	 * 						//Maybe loop between AutoDrive and AutoTarget
	 * 							AutoTarget();
	 * 							Shoot();
	 * 							break;
	 * 					}
	 * 					break;
	 * 			}
	 * 			break;
	 * 		case 4:
	 * 			switch(GoalPosition)
	 * 			{
	 * 				case 1:
	 * 					AutoTurn() left 90
	 * 					AutoDrive()
	 * 					AdjustAngle straight
	 * 					AutoTurn() right 90
	 * 					AutoDrive() up to appropriate distance from goal
	 * 					AdjustAngle straight
	 * 					AutoTutn() turns directly towards goal
	 * 					switch(LowOrHigh)
	 * 					{
	 * 						case 1:
	 * 							AutoDrive(); To front of low goal
	 * 							OutFeed(); AKA low kick
	 * 							break;
	 * 						case 2:
	 * 						//Maybe loop between AutoDrive and AutoTarget
	 * 							AutoTarget();
	 * 							Shoot();
	 * 							break;
	 * 					}
	 * 					break;
	 * 				case 2:
	 * 					AutoTurn() left 90
	 * 					AutoDrive()
	 * 					AdjustAngle straight
	 * 					AutoTurn() Left 90
	 * 					AutoDrive() up to appropriate distance from goal
	 * 					//Maybe loop between AutoDrive and AutoTarget
	 * 					AutoTarget();
	 * 					Shoot();
	 * 					break;
	 * 				case 3:
	 * 					AutoTurn() Right 90
	 * 					AutoDrive() until it goes over the secret passage boundary
	 * 					AdjustAngle straight for after going over boundary
	 * 					AutoDrive() for the rest of the distance after boundary
	 * 					AdjustAngle() Make sure it's straight
	 * 					AutoTurn() Left 90
	 * 					AutoDrive() up to appropriate distance from goal
	 * 					AutoTurn() turns towards goal
	 * 					switch(LowOrHigh)
	 * 					{
	 * 						case 1:
	 * 							AutoDrive(); To In front of goal
	 * 							OutFeed(); AKA low kick
	 * 							break;
	 * 						case 2:
	 * 						//Maybe loop between AutoDrive and AutoTarget
	 * 							AutoTarget();
	 * 							Shoot();
	 * 							break;
	 * 					}
	 * 					break;
	 * 			}
	 * 			break;
	 * 		case 5:
	 * 			switch(GoalPosition)
	 * 			{
	 * 				case 1:
	 * 					AutoTurn() left 90
	 * 					AutoDrive()
	 * 					AdjustAngle straight
	 * 					AutoTurn() right 90
	 * 					AutoDrive() up to appropriate distance from goal
	 * 					AdjustAngle straight
	 * 					AutoTutn() turns directly towards goal
	 * 					switch(LowOrHigh)
	 * 					{
	 * 						case 1:
	 * 							AutoDrive(); To front of low goal
	 * 							OutFeed(); AKA low kick
	 * 							break;
	 * 						case 2:
	 * 						//Maybe loop between AutoDrive and AutoTarget
	 * 							AutoTarget();
	 * 							Shoot();
	 * 							break;
	 * 					}
	 * 					break;
	 * 				case 2:
	 * 					AutoTurn() left 90
	 * 					AutoDrive()
	 * 					AdjustAngle straight
	 * 					AutoTurn() Left 90
	 * 					AutoDrive() up to appropriate distance from goal
	 * 					//Maybe loop between AutoDrive and AutoTarget
	 * 					AutoTarget();
	 * 					Shoot();
	 * 					break;
	 * 				case 3:
	 * 					AutoTurn() Right 90
	 * 					AutoDrive() until it goes over the secret passage boundary
	 * 					AdjustAngle straight for after going over boundary
	 * 					AutoDrive() for the rest of the distance after boundary
	 * 					AdjustAngle() Make sure it's straight
	 * 					AutoTurn() Left 90
	 * 					AutoDrive() up to appropriate distance from goal
	 * 					AutoTurn() turns towards goal
	 * 					switch(LowOrHigh)
	 * 					{
	 * 						case 1:
	 * 							AutoDrive(); To In front of goal
	 * 							OutFeed(); AKA low kick
	 * 							break;
	 * 						case 2:
	 * 						//Maybe loop between AutoDrive and AutoTarget
	 * 							AutoTarget();
	 * 							Shoot();
	 * 							break;
	 * 					}
	 * 					break;
	 * 			}
	 * 			break;
	 * 	}
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
