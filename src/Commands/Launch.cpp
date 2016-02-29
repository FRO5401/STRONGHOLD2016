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
  Requires(spt);
  Requires(relaysys);
}
void Launch::Initialize()
{
	spt -> ClearShooterPathPosition();
	shooter	->	Shoot();
	relaysys -> ShootLights(2);
}

void Launch::Execute(){};

bool Launch::IsFinished()
{
	return true;
}

void Launch::End(){

	shooter ->  Reset();

};
void Launch::Interrupted(){};



