#include "Autonomous/AutonomousChevalDeFrise.h"
#include "Autonomous/AutoDriveCommand.h"
#include "Autonomous/AutoDeliverBall.h"
#include "Autonomous/AutoTurnToAngleCommand.h"
#include "Autonomous/AutoTurnAngleCommand.h"

#include "Commands/AutoLaunch.h"
#include "Commands/FeederStop.h"
#include "Commands/FeedOutFromOuter.h"
#include "Commands/FeedOutFromInner.h"
#include "Commands/SPTMoveToPosition.h"
#include "Commands/HookShoulderMoveToPosition.h"
//#include "MoveSPTtoPosition.h"

AutonomousChevalDeFrise::AutonomousChevalDeFrise(int DefensePosition, int GoalPosition, int LowOrHigh)
{
	//SPT must be in the front
	AddParallel(new HookShoulderMoveToPosition(45));//TODO change Position
 	AddSequential(new AutoDriveCommand(46)); //Drive to defense //TODO edit
	AddSequential(new SPTMoveToPosition(192)); //Move SPT down to prepare to drive over cheval
	AddParallel(new SPTMoveToPosition(90)); //Move SPT up and out of the way
	AddSequential(new AutoDriveCommand(60)); //TODO determine best distance to drive //Drive over cheval.//updated 3/5/16 10:00am



	//Cheval Code Only does middle goal, SPT must be up before entering the switch statements SPT must be in front
	//Code is commented out because it used AutoTurnToAngle which is no longer being used
/*	switch(DefensePosition)
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
	 						//LowGoal
	  						case 1:
	  							AddSequential(new SPTMoveToPosition(192)); //TODO find position of spt in feeder position
	  							AddSequential(new AutoDriveCommand(130)); //To front of low goal
	  							AddParallel(new FeedOutFromOuter());
	  							AddSequential(new FeedOutFromInner());
	 							WaitCommand(2);
	 							AddSequential(new FeederStop());


	  							break;
	 						//HighGoal
	 						case 2:
	 							AddParallel(new AutoTurnAngleCommand(180));
	 							AddSequential(new AutoDeliverBall(2));// TODO find time
//	  							AddSequential(new AutoLaunch());
	  							break;
	  					}
	  					break;
	 				//The following is for Defense position 2 and the Middel Goal
	  				case 2:
	  					AddSequential(new AutoTurnToAngleCommand(90));
	  					AddSequential(new AutoDriveCommand(94));
	  					AddSequential(new AutoTurnToAngleCommand(-180));
	 					AddSequential(new AutoDeliverBall(2));
//	  					AddSequential(new AutoLaunch());
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
	 						//LowGoal
	  						case 1:
	  							AddSequential(new SPTMoveToPosition(192)); //TODO find position of spt in feeder position
	  							AddSequential(new AutoDriveCommand(130));//To front of low goal
	  							AddParallel(new FeedOutFromOuter());
	  							AddSequential(new FeedOutFromInner());
	 							WaitCommand(2);
	 							AddSequential(new FeederStop());


	  							break;
	 						//HighGoal
	 						case 2:
	 							AddParallel(new AutoTurnAngleCommand(180));
	 							AddSequential(new AutoDeliverBall(2));// TODO find time
//	  							AddSequential(new AutoLaunch());
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
	  					{						//LowGoal
	  						case 1:
	  							AddSequential(new SPTMoveToPosition(192)); //TODO find position of spt in feeder position
	  							AddSequential(new AutoDriveCommand(130));// To front of low goal
	  							AddParallel(new FeedOutFromOuter());
	  							AddSequential(new FeedOutFromInner());
	 							WaitCommand(2);
	 							AddSequential(new FeederStop());


	  							break;
	 						//HighGoal
	 						case 2:
	 							AddParallel(new AutoTurnAngleCommand(180));
	 							AddSequential(new AutoDeliverBall(2));// TODO find time
//	  							AddSequential(new AutoLaunch());
	  							break;
	  					}
	  					break;
	 				//The following is for Defense position 3 and the Middel Goal
	  				case 2:
	  					AddSequential(new AutoTurnToAngleCommand(90));
	  					AddSequential(new AutoDriveCommand(44));
	  					AddSequential(new AutoTurnToAngleCommand(-180));
	 					AddSequential(new AutoDeliverBall(2));
//	  					AddSequential(new AutoLaunch());
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
	 						//LowGoal
	  						case 1:
	  							AddSequential(new SPTMoveToPosition(192)); //TODO find position of spt in feeder position
	  							AddSequential(new AutoDriveCommand(130));// To front of low goal
	  							AddParallel(new FeedOutFromOuter());
	  							AddSequential(new FeedOutFromInner());
	 							WaitCommand(2);
	 							AddSequential(new FeederStop());


	  							break;
	 						//HighGoal
	 						case 2:
	 							AddParallel(new AutoTurnAngleCommand(180));
	 							AddSequential(new AutoDeliverBall(2));// TODO find time
//	  							AddSequential(new AutoLaunch());
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
	 						//LowGoal
	  						case 1:
	  							AddSequential(new SPTMoveToPosition(192)); //TODO find position of spt in feeder position, fix position
	  							AddSequential(new AutoDriveCommand(130));// To front of low goal
	  							AddParallel(new FeedOutFromOuter());
	  							AddSequential(new FeedOutFromInner());
	 							WaitCommand(2);
	 							AddSequential(new FeederStop());


	  							break;
	 						//HighGoal
	 						case 2:
	 							AddParallel(new AutoTurnAngleCommand(180));
	 							AddSequential(new AutoDeliverBall(2));// TODO find time
//	  							AddSequential(new AutoLaunch());
	  							break;
	  					}
	  					break;
	 				//The following is for Defense position 4 and the Middel Goal
	  				case 2:
	  					AddSequential(new AutoTurnToAngleCommand(-90));
	  					AddSequential(new AutoDriveCommand(6));
	  					AddSequential(new AutoTurnToAngleCommand(-180));
	 					AddSequential(new AutoDeliverBall(2));
//	  					AddSequential(new AutoLaunch());
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
	 						//LowGoal
	  						case 1:
	  							AddSequential(new SPTMoveToPosition(192)); //TODO find position of spt in feeder position
	  							AddSequential(new AutoDriveCommand(130));// To front of low goal
	  							AddParallel(new FeedOutFromOuter());
	  							AddSequential(new FeedOutFromInner());
	 							WaitCommand(2);
	 							AddSequential(new FeederStop());


	  							break;
	 						//HighGoal
	 						case 2:
	 							AddParallel(new AutoTurnAngleCommand(180));
	 							AddSequential(new AutoDeliverBall(2));// TODO find time
//	  							AddSequential(new AutoLaunch());
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
	 						//LowGoal
	  						case 1:
	  							AddSequential(new SPTMoveToPosition(192)); //TODO find position of spt in feeder position
	  							AddSequential(new AutoDriveCommand(130)); //To front of low goal
	  							AddParallel(new FeedOutFromOuter());
	  							AddSequential(new FeedOutFromInner());
	 							WaitCommand(2);
	 							AddSequential(new FeederStop());


	  							break;
	 						//HighGoal
	 						case 2:
	 							AddParallel(new AutoTurnAngleCommand(180));
	 							AddSequential(new AutoDeliverBall(2));// TODO find time
//	  							AddSequential(new AutoLaunch());
	  							break;
	  					}
	  					break;
	 				//The following is for Defense position 5 and the Middel Goal
	  				case 2:
	  					AddSequential(new AutoTurnToAngleCommand(-90));
	  					AddSequential(new AutoDriveCommand(56));
	  					AddSequential(new AutoTurnToAngleCommand(0));
	 					AddParallel(new AutoTurnAngleCommand(180));
	 					AddSequential(new AutoDeliverBall(2));
//	  					AddSequential(new AutoLaunch());
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
	  							AddSequential(new SPTMoveToPosition(192)); //TODO find position of spt in feeder position
	  							AddSequential(new AutoDriveCommand(130));// To front of low goal
	  							AddParallel(new FeedOutFromOuter());
	  							AddSequential(new FeedOutFromInner());
	 							AddSequential(new WaitCommand(2));
	 							AddSequential(new FeederStop());

	  							break;
	  						case 2:
	 							AddParallel(new AutoTurnAngleCommand(180));
	 							AddSequential(new AutoDeliverBall(2));// TODO find time
//	  							AddSequential(new AutoLaunch());
	  							break;
	  					}
	  					break;
	  			}
	  			break;
	 	}
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
