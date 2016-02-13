#include "RelaySys.h"
#include "../RobotMap.h"

RelaySys::RelaySys() :
		Subsystem("RelaySys")
{
	  LightRing 	= new Relay(LightRing_Channel);

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

