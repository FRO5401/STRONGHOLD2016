/*
 * Short hook subsystem for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * Manipulates drawbridge and sally port
 * If the robot weighs the same as a duck, then it must be made of wood?
 */

#include "ShortHook.h"
#include "../RobotMap.h"

ShortHook::ShortHook() :
		Subsystem("ShortHook")
{

	ShortHookExtend 	=	new DoubleSolenoid(SolenoidCAN_ID, ShortHookFwd_Channel, ShortHookRev_Channel);
	//Removed pneumatics
}

void ShortHook::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
//code here should determine if the parameter is forward to extend forward, or false to retract
void ShortHook::Extend()
{
	if (Fwd) {
		ShortHookExtend 	-> Set(DoubleSolenoid::Value::kForward);
	} else {
		ShortHookExtend 	-> Set(DoubleSolenoid::Value::kReverse);
	}
}
