/*
 * Catapult manual override command for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * Required in event boulder is stuck under arm/other jam
 */

#include "ShooterOverride.h"
#include "RobotMap.h"

ShooterOverride::ShooterOverride()
{
  Requires(shooter);
  ShooterMove = 0;
}
	void ShooterOverride::Initialize() { };

	void ShooterOverride::Execute(){

		bool Button = oi -> GetButtonR3();

		if (Button){
			ShooterMove		=	oi	->  ReadXboxRightStickY();
		} else {
			ShooterMove = 0;//		bool	OverridePressed	=	oi	->	GetButtonR3(); //probably not needed
		}
		shooter        -> Override(ShooterMove);

	};

	bool ShooterOverride::IsFinished()
{
	bool	Override	=	oi	->	GetButtonR3();
	return false;/*(!Override)*/;
}

	void ShooterOverride::End(){
		shooter -> Stop();
	};
	void ShooterOverride::Interrupted(){};




