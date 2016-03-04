#include "Autonomous/AutonomousChevalDeFrise.h"
#include "Autonomous/AutoDriveCommand.h"
#include "Autonomous/AutoDeliverBall.h"
#include "Autonomous/AutoTurnToAngleCommand.h"

#include "Commands/AutoLaunch.h"
#include "Commands/MoveSPTtoPosition.h"

AutonomousChevalDeFrise::AutonomousChevalDeFrise(int DefensePosition, int GoalPosition, int LowOrHigh)
{
 	 AddSequential(new AutoDriveCommand(46)); //Drive to defense
 	 AddSequential(new MoveSPTtoPosition(-39.103)); //Move SPT down to prepare to drive over cheval
 	 AddParallel(new MoveSPTtoPosition(55)); //Move SPT up and out of the way to delivery position
	 AddSequential(new AutoDriveCommand(90)); //TODO determine best distance to drive //Drive over cheval
/*	 switch(DefensePosition)
	 	{
	  		case 2:
	  			switch(GoalPosition)
	  			{	//The following is for Defense position 2 and Left Goal
	 	 			case 1:
	  					AddSequential(new AutoTurnToAngleCommand(-90));
	  					AddSequential(new AutoDriveCommand(43));
	  					AddSequential(new AutoTurnToAngleCommand(0));
	  					AddSequential(new AutoDriveCommand(104)); //up to appropriate distance from goal
	  					AddSequential(new AutoTurnToAngleCommand(50)); //turns directly towards goal TODO figure out the correct angle

	 					switch(LowOrHigh) //Decides to shoot or go forward for low goal
	  					{
	  						//Low goal
	 						case 1:
	 							AddSequential(new MoveSPTtoPosition()); //TODO find position of spt in feeder position
	  							AddSequential(new AutoDriveCommand(130)); To front of low goal
	  							AddSequential(new AutoOutFeed()); //TODO make this command AKA low kick
	  							break;
	 						//high goal
	  						case 2:
	  							AddSequential(new AutoDeliverBall(2.0));
	  							AddSequential(new AutoLaunch());
	  							break;
	  					}
	  					break;
	 				//The following is for Defense position 2 and the Middel Goal
	  				case 2:
	  					AddSequential(new AutoTurnToAngleCommand(90));
	  					AddSequential(new AutoDriveCommand(94));
	  					AddSequential(new AutoTurnToAngleCommand(0));
	  					AddSequential(new AutoDeliverBall(2.0));
	  					AddSequential(new AutoLaunch());
	  					//No Low goal in middle
	  					break;

	  				case 3: //Defense position 2 and Right Goal
	  					AddSequential(new AutoTurnToAngleCommand(90));
	  					AddSequential(new AutoDriveCommand(211)); //until it goes over the secret passage boundary
	  					AddSequential(new AutoTurnToAngleCommand(0));
	  					AddSequential(new AutoDriveCommand(104)); //TODO edit distance //for the rest of the distance after boundary
	  					AddSequential(new AutoTurnToAngleCommand(-50));//TODO edit this

	 					switch(LowOrHigh)//Decides to shoot or go forward for low goal
	  					{
	  						case 1:
	  							AddSequential(new MoveSPTtoPosition()); //TODO find position of spt in feeder position
	  							AddSequential(new AutoDriveCommand(130)); To front of low goal
	  							AddSequential(new AutoOutFeed()); //TODO make this command AKA low kick
	  							break;
	  						case 2:
	  							AddSequential(new AutoDeliverBall(2.0));
	  							AddSequential(new AutoLaunch());
	  							break;
	  					}
	  					break;
	  			}
	  			break;
	  		case 3:
	  			switch(GoalPosition)
	  			{	//The following is for Defense position 3 and Left Goal
	 	 			case 1:
	  					AddSequential(new AutoTurnToAngleCommand(-90));
	  					AddSequential(new AutoDriveCommand(93));
	  					AddSequential(new AutoTurnToAngleCommand(0));
	  					AddSequential(new AutoDriveCommand(104)); //up to appropriate distance from goal
	  					AddSequential(new AutoTurnToAngleCommand(50)); //turns directly towards goal TODO figure out the correct angle

	 					switch(LowOrHigh) //Decides to shoot or go forward for low goal
	  					{
	  						//Low goal
	 						case 1:
	 							AddSequential(new MoveSPTtoPosition()); //TODO find position of spt in feeder position
	  							AddSequential(new AutoDriveCommand(130)); To front of low goal
	  							AddSequential(new AutoOutFeed()); //TODO make this command AKA low kick
	  							break;
	 						//high goal
	  						case 2:
	  							AddSequential(new AutoDeliverBall(2.0));
	  							AddSequential(new AutoLaunch());
	  							break;
	  					}
	  					break;
	 				//The following is for Defense position 3 and the Middel Goal
	  				case 2:
	  					AddSequential(new AutoTurnToAngleCommand(90));
	  					AddSequential(new AutoDriveCommand(44));
	  					AddSequential(new AutoTurnToAngleCommand(0));
	  					AddSequential(new AutoDeliverBall(2.0));
	  					AddSequential(new AutoLaunch());
	  					//No Low goal in middle
	  					break;

	  				case 3: //Defense position 3 and Right Goal
	  					AddSequential(new AutoTurnToAngleCommand(90));
	  					AddSequential(new AutoDriveCommand(161)); //until it goes over the secret passage boundary
	  					AddSequential(new AutoTurnToAngleCommand(0));
	  					AddSequential(new AutoDriveCommand(104)); //TODO edit distance //for the rest of the distance after boundary
	  					AddSequential(new AutoTurnToAngleCommand(-50));//TODO edit this

	 					switch(LowOrHigh)//Decides to shoot or go forward for low goal
	  					{
	  						case 1:
	  							AddSequential(new MoveSPTtoPosition()); //TODO find position of spt in feeder position
	  							AddSequential(new AutoDriveCommand(130)); To front of low goal
	  							AddSequential(new AutoOutFeed()); //TODO make this command AKA low kick
	  							break;
	  						case 2:
	  							AddSequential(new AutoDeliverBall(2.0));
	  							AddSequential(new AutoLaunch());
	  							break;
	  					}
	  					break;
	  			}
	  			break;
	  		case 4:
	  			switch(GoalPosition)
	  			{	//The following is for Defense position 4 and Left Goal
	 	 			case 1:
	  					AddSequential(new AutoTurnToAngleCommand(-90));
	  					AddSequential(new AutoDriveCommand(143));
	  					AddSequential(new AutoTurnToAngleCommand(0));
	  					AddSequential(new AutoDriveCommand(104)); //up to appropriate distance from goal
	  					AddSequential(new AutoTurnToAngleCommand(50)); //turns directly towards goal TODO figure out the correct angle

	 					switch(LowOrHigh) //Decides to shoot or go forward for low goal
	  					{
	  						//Low goal
	 						case 1:
	 							AddSequential(new MoveSPTtoPosition()); //TODO find position of spt in feeder position
	  							AddSequential(new AutoDriveCommand(130)); To front of low goal
	  							AddSequential(new AutoOutFeed()); //TODO make this command AKA low kick
	  							break;
	 						//high goal
	  						case 2:
	  							AddSequential(new AutoDeliverBall(2.0));
	  							AddSequential(new AutoLaunch());
	  							break;
	  					}
	  					break;
	 				//The following is for Defense position 4 and the Middel Goal
	  				case 2:
	  					AddSequential(new AutoTurnToAngleCommand(-90));
	  					AddSequential(new AutoDriveCommand(6));
	  					AddSequential(new AutoTurnToAngleCommand(0));
	  					AddSequential(new AutoDeliverBall(2.0));
	  					AddSequential(new AutoLaunch());
	  					//No Low goal in middle
	  					break;
	 				//Defense position 4 and Right Goal
	  				case 3:
	  					AddSequential(new AutoTurnToAngleCommand(90));
	  					AddSequential(new AutoDriveCommand(111)); //until it goes over the secret passage boundary
	  					AddSequential(new AutoTurnToAngleCommand(0));
	  					AddSequential(new AutoDriveCommand(104)); //TODO edit distance //for the rest of the distance after boundary
	  					AddSequential(new AutoTurnToAngleCommand(-50));//TODO edit this

	 					switch(LowOrHigh)//Decides to shoot or go forward for low goal
	  					{
	  						case 1:
	  							AddSequential(new MoveSPTtoPosition()); //TODO find position of spt in feeder position
	  							AddSequential(new AutoDriveCommand(130)); To front of low goal
	  							AddSequential(new AutoOutFeed()); //TODO make this command AKA low kick
	  							break;
	  						case 2:
	  							AddSequential(new AutoDeliverBall(2.0));
	  							AddSequential(new AutoLaunch());
	  							break;
	  					}
	  					break;
	  			}
	  			break;
	  		case 5:

	  			switch(GoalPosition)
	  			{	//The following is for Defense position 5 and Left Goal
	 	 			case 1:
	  					AddSequential(new AutoTurnToAngleCommand(-90));
	  					AddSequential(new AutoDriveCommand(193));
	  					AddSequential(new AutoTurnToAngleCommand(0));
	  					AddSequential(new AutoDriveCommand(104)); //up to appropriate distance from goal
	  					AddSequential(new AutoTurnToAngleCommand(50)); //turns directly towards goal TODO figure out the correct angle

	 					switch(LowOrHigh) //Decides to shoot or go forward for low goal
	  					{
	  						//Low goal
	 						case 1:
	 							AddSequential(new MoveSPTtoPosition()); //TODO find position of spt in feeder position
	  							AddSequential(new AutoDriveCommand(130)); To front of low goal
	  							AddSequential(new AutoOutFeed()); //TODO make this command AKA low kick
	  							break;
	 						//high goal
	  						case 2:
	  							AddSequential(new AutoDeliverBall(2.0));
	  							AddSequential(new AutoLaunch());
	  							break;
	  					}
	  					break;
	 				//The following is for Defense position 5 and the Middle Goal
	  				case 2:
	  					AddSequential(new AutoTurnToAngleCommand(-90));
	  					AddSequential(new AutoDriveCommand(56));
	  					AddSequential(new AutoTurntOAngleCommand(0));
	  					AddSequential(new AutoDeliverBall(2.0));
	  					AddSequential(new AutoLaunch());
	  					//No Low goal in middle
	  					break;
	 				//Defense position 5 and Right Goal
	  				case 3:
	  					AddSequential(new AutoTurnToAngleCommand(90));
	  					AddSequential(new AutoDriveCommand(61)); //until it goes over the secret passage boundary
	  					AddSequential(new AutoTurnToAngleCommand(0));
	  					AddSequential(new AutoDriveCommand(104)); //TODO edit distance //for the rest of the distance after boundary
	  					AddSequential(new AutoTurnToAngleCommand(-50));//TODO edit this

	 					switch(LowOrHigh)//Decides to shoot or go forward for low goal
	  					{
	  						case 1:
	  							AddSequential(new MoveSPTtoPosition()); //TODO find position of spt in feeder position
	  							AddSequential(new AutoDriveCommand(130)); To front of low goal
	  							AddSequential(new AutoOutFeed()); //TODO make this command AKA low kick
	  							break;
	  						case 2:
	  							AddSequential(new AutoDeliverBall(2.0));
	  							AddSequential(new AutoLaunch());
	  							break;
	  					}
	  					break;
	  			}
	  			break;
			}
*/
	/*	PsuedoCode V. 2.0
	 * 	AdjustAngle() so it's straight or angled correctly 	MAYBE???
	 * 	AddSequential(new AutoDriveCommand());
	 * 	AddSequential(new SPT down to horizontal);
	 * 	AddSequential(new AutoDrive()); //very small
	 * 	AddParallel(new AutoDrive());
	 * 	AddParallel(new SPT Shooter position);
	 * 	AdjustAngle(0) so it's straight
	 *
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
