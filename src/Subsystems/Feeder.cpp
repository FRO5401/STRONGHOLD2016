/*
 * Infeed subsystem for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * A five ounce bird could not carry a one pound coconut.
 */

#include "Feeder.h"
#include "../RobotMap.h"

const float InfeedIn	= 0.95; //Set max speed for infeed motors
const float InfeedOut	= 0.9; //Set max speed for infeed motor kick
const float DeliveryGo	= 0.75; //Set max speed for Delivery motors

Feeder::Feeder() :
		Subsystem("Feeder")
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
	FeederOuterFasterMotor -> Set(InfeedIn);
}

void Feeder::FeedOutToField(){
	FeederOuterFasterMotor -> Set(-1 * InfeedOut);
}

void Feeder::FeedToShooter(){
	FeederInnerSlowerMotor -> Set(DeliveryGo);
}
// KJM Not sure what this is.
void Feeder::FeedOutFromShooter(){
	FeederInnerSlowerMotor -> Set(-DeliveryGo);
}

void Feeder::StopFeed(){
	FeederOuterFasterMotor -> Set(0);
	FeederInnerSlowerMotor -> Set(0);
}

