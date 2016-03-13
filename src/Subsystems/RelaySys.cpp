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
	// @REVIEW NJL: This is called from AutoLaunch::Execute.  Execute must return quickly, so a loop that takes time is not appropriate here.
	for ( int i = 0; i < j; i++ ) {
		CarriageLights ->	Set(Relay::Value::kOn);
		Wait(timing);  // @REVIEW NJL: How long does this take?  All Execute calls must return within 20ms, so any delay longer than 1ms or so threatens real time responsiveness.
		CarriageLights -> 	Set(Relay::Value::kOff);
		Wait(timing);
	}
}
