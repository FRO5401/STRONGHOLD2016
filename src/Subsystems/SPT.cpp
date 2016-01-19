#include "SPT.h"
#include "../RobotMap.h"

SPT::SPT() :
		Subsystem("SPT")
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
//This function sets the shoulder motor of SPT to a certain direction between up and down
void SPT::UpAndDown(double ShoulderChangeValue){
	SPTShoulderMotor -> Set(-.5 * ShoulderChangeValue);
}

//This function sets the shoulder motor to a certain speed
//The waits a while and stops the motor at the correct angle
//The wait amount is guess and checked.
void SPT::MoveToDeliveryPosition(){
	SPTShoulderMotor -> Set(.5);//Speed set may change
	Wait(1);					//Wait amount may change
	SPTShoulderMotor -> Set(0);

}

void SPT::MoveToInfeederPosition(){
	SPTShoulderMotor -> Set(.5);
	Wait(1);
	SPTShoulderMotor -> Set(0);
}
