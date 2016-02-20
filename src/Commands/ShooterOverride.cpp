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
		ShooterMove		=	oi	->  ReadXboxRightStickY();

		if (Button){
			shooter        -> Override(ShooterMove);
		}//		bool	OverridePressed	=	oi	->	GetButtonR3(); //probably not needed

	};

	bool ShooterOverride::IsFinished()
{
	bool	Override	=	oi	->	GetButtonR3();
	return (!Override);
}

	void ShooterOverride::End(){};
	void ShooterOverride::Interrupted(){};




