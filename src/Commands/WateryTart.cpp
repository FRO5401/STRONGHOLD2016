/*
 * Catapult targeting for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 */

#include "Target.h"
#include "RobotMap.h"
bool Lock;

Target::Target()
{
  Requires(drivebase);
}
	void Target::Initialize() { };

	void Target::Execute(){
/*
 * This will do image processing, to locate the target and properly move the robot to the launch site
 * Then it will set a bool flag Lock to indicate target lock
 * When finished, it will kick off the launch command
 */
	};

	bool Target::IsFinished()
{
	return Lock;
}

	void Target::End(){
//		new Launch();
	}

	void Target::Interrupted(){};
