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

void RelaySys::ShootLights(int j)
{
	float timing = (1/6); //NASA says eye is most sensitive to lights between 4-8 Hz, therefore setting to 6 Hz
	for ( int i = 0; i < j; i++ ) {
		CarriageLights ->	Set(Relay::Value::kOn);
		Wait(timing);
		CarriageLights -> 	Set(Relay::Value::kOff);
		Wait(timing);
	}
}
