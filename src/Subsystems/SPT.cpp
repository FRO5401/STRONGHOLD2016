#include "SPT.h"
#include "../RobotMap.h"

SPT::SPT() :
		Subsystem("SPT")
{
	SPTShoulderMotor = new Victor(SPTShoulderMotor_Channel);
													//vv Multiplier to get meaningful value. A number can be put here
	SPTPot = new AnalogPotentiometer(SPTPot_Channel, SPT_Range, SPT_Offset);
							//		 ^^Channel in RobotMap       ^^Quote "offset added to the scaled value to control the 0 value

	//Format for declaring PIDControllers (Kp value, Ki value, Kd value, the input source, the output source)
	//Kp is proportional, Ki is intergral, and Kd is derivative, all are constants
	//Read Control Theory from http://www.chiefdelphi.com/media/papers/1823
	SPTPotPID = new PIDController(SPT_Kp, SPT_Ki, SPT_Kd, SPTPot, SPTShoulderMotor);
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
