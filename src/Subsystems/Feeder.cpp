/*
 * Infeed subsystem for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * A five ounce bird could not carry a one pound coconut.
 */

#include "Feeder.h"
#include "../RobotMap.h"

Feeder::Feeder() :
		Subsystem("ExampleSubsystem")
{
	FeederOuterFasterMotor = new Victor(FeederOuterFasterMotor_Channel);
	FeederInnerSlowerMotor = new Victor(FeederInnerSlower_Channel);
}

void Feeder::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Feeder::FeedInFromField(){
	FeederOuterFasterMotor -> Set(1);
}

void Feeder::FeedOutToField(){
	FeederOuterFasterMotor -> Set(-1);
}

void Feeder::FeedToShooter(){
	FeederInnerSlowerMotor -> Set(0.5);
}

void Feeder::FeedOutFromShooter(){
	FeederInnerSlowerMotor -> Set(-0.5);
}

void Feeder::StopFeed(){
	FeederOuterFasterMotor -> Set(0);
	FeederInnerSlowerMotor -> Set(0);
}

