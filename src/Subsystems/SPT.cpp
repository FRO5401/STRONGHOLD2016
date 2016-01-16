#include "SPT.h"
#include "../RobotMap.h"

SPT::SPT() :
		Subsystem("ExampleSubsystem")
{
	SPTShoulderMotor = new Victor(SPTShoulderMotor_Channel);
}

void SPT::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void UpAndDown(double ShoulderChangeValue){
	SPTShoulderMotor -> Set(-1 * ShoulderChangeValue);
}


void MoveToDeliveryPosition(){

}
