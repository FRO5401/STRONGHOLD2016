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
		double 	ShooterMove		=	oi	->	DummyJoystickReadFunction();//Define function once we figure out controller
		bool	OverridePressed	=	oi	->	DummyButtonReadFunction();//Define function once we figure out controller

		shooter        -> Override(ShooterMove);

	};

	bool ShooterOverride::IsFinished()
{
	bool	Override	=	oi	->	DummyButtonReadFunction();//Define function once we figure out controller
	return (!Override);
}

	void ShooterOverride::End(){};
	void ShooterOverride::Interrupted(){};




