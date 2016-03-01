/*
 * Catapult launch command for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 */


#include "Launch.h"
#include "RobotMap.h"

const double ShooterFiredPosition = 85;

Launch::Launch()
{
  Requires(shooter);
  LaunchComplete = true;
}
void Launch::Initialize()
{
	spt -> ClearShooterPathPosition();
}

void Launch::Execute(){
	if (shooter -> ReportEncoder() < ShooterFiredPosition){
	LaunchComplete = false;
	shooter	->	Shoot();
//	relaysys -> ShootLights(2);
	} else {
		LaunchComplete = true;
		}
}

bool Launch::IsFinished()
{
	return LaunchComplete;
}

void Launch::End(){
	shooter -> Stop();

};
void Launch::Interrupted(){
	shooter -> Stop();

};



