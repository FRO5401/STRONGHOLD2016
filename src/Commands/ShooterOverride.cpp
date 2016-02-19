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
}
	void ShooterOverride::Initialize() { };

	void ShooterOverride::Execute(){
		double 	ShooterMove		=	oi	->  ReadMOHRightStickY();
		bool	OverridePressed	=	oi	->	GetMOHRightStickButton();

		shooter        -> Override(ShooterMove);
	};

	bool ShooterOverride::IsFinished()
{
	bool	Override	=	oi	->	GetMOHRightStickButton();
	return (!Override);
}

	void ShooterOverride::End(){};
	void ShooterOverride::Interrupted(){};




