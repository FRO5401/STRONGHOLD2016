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
	shooter -> ResetEncoder();
	shooter -> Stop();
}

void Launch::Execute(){
	bool Abort = oi -> GetXboxRightStickButton();
	if(!Abort){
	shooter	->	Shoot();
	if (shooter -> ReportEncoder() < ShooterFiredPosition){
	LaunchComplete = false;
//	relaysys -> ShootLights(2);
	} else {
		LaunchComplete = true;
		}
	} else LaunchComplete = true;
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



