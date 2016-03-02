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
  Requires(spt);
  LaunchComplete = true;
}
void Launch::Initialize()
{
	spt -> ClearShooterPathPosition();
	shooter -> ResetEncoder();

}

void Launch::Execute(){
	shooter	->	Shoot();
	if (shooter -> ReportEncoder() < ShooterFiredPosition){
	LaunchComplete = false;
	std::cout << ("Launching\n");
//	relaysys -> ShootLights(2);
	} else {
		LaunchComplete = true;
				std::cout << ("Launch complete\n");
		}
}

bool Launch::IsFinished()
{
	return LaunchComplete;
}

void Launch::End(){
	std::cout << ("Launch Ending\n");

	shooter -> Stop();
	std::cout << ("Shooter stop, end launch\n");

}
void Launch::Interrupted(){
	std::cout << ("Launch interrupted\n");
	shooter -> Stop();
	std::cout << ("Shooter stopped, interrupt\n");

}



