#include "RelaySys.h"
#include "../RobotMap.h"

RelaySys::RelaySys() :
		Subsystem("RelaySys")
{
	  LightRing 	= new Relay(LightRing_Channel);
	  CarriageLights	= new Relay(CarriageLights_Channel);
}

void RelaySys::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void RelaySys::TurnOn()
{
	LightRing ->	Set(Relay::Value::kOn);
}

void RelaySys::TurnOff()
{
	LightRing -> Set(Relay::Value::kOff);
}

void RelaySys::ShootLights()
{
	for ( int i = 0; i < 5; i++ ) {
		CarriageLights ->	Set(Relay::Value::kOn);
		Wait(0.1);
		CarriageLights -> 	Set(Relay::Value::kOff);
		Wait(0.1);
	}
}
