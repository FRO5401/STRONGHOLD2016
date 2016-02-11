/*
 * Catapult launch command for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 */


#include "Launch.h"
#include "RobotMap.h"

Launch::Launch()
{
  Requires(shooter);
}
void Launch::Initialize()
{
	shooter	->	Shoot();
}

void Launch::Execute(){};

bool Launch::IsFinished()
{
	return true;
}

void Launch::End(){};
void Launch::Interrupted(){};



