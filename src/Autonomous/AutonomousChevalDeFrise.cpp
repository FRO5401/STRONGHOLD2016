#include "Autonomous/AutonomousChevalDeFrise.h"
#include "Autonomous/AutoDriveCommand.h"
#include "Autonomous/AutoDeliverBall.h"
#include "Autonomous/AutoTurnToAngleCommand.h"

#include "Commands/AutoLaunch.h"

AutonomousChevalDeFrise::AutonomousChevalDeFrise(int DefensePosition, int GoalPosition, int LowOrHigh)
{
 	 AddSequential(new AutoDriveCommand(46)); //Drive to defense
//TODO	 AddSequential(new MoveSPTtoPosition(-39.103)); //Move SPT down to prepare to drive over cheval
//TODO Change to new command	 AddParallel(new InfeederLiftIntoDelivery()); //Move SPT up and out of the way
	 AddSequential(new AutoDriveCommand(70)); //TODO determine best distance to drive //Drive over cheval
	 //Determine which goal to shoot at
	 //If needed
	 //	AddSequential(new AutoTurnToAngleCommand(determine angle)); //turn to drive
	 // AddSequential(new AutoDriveCommand(length varies)); //Drive forward to get a good angle
	 //	AddSequential(new AutoTurnToAngleCommand(determine angle)); //Turn to goal
	 AddSequential(new AutoDeliverBall(2.0)); //Feeds ball into shooter
	 AddSequential(new AutoLaunch()); //Shoot and score!
	/*	PsuedoCode V. 2.0
	 * 	AdjustAngle() so it's straight or angled correctly 	MAYBE???
	 * 	AddSequential(new AutoDriveCommand());
	 * 	AddSequential(new SPT down to horizontal);
	 * 	AddSequential(new AutoDrive()); //very small
	 * 	AddParallel(new AutoDrive());
	 * 	AddParallel(new SPT Shooter position);
	 * 	AdjustAngle(0) so it's straight
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
