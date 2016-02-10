/*
 * Infeeder head subsystem - "Sharp Pointy Teeth" - for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * Follow only if ye be men of valor! For the entrance to this subsystem is guarded by a creature so foul,
 * so cruel, that no programmer yet has fought with it... and lived! BONES of full fifty men lie *strewn*
 * about its lair! So! Brave knights! If you do doubt your courage or your strength, come no further,
 * for death awaits you all with nasty, big, pointy teeth...
 *
 * */


#include "SPT.h"
#include "../RobotMap.h"
#include "PIDController.h"

//Parameters for Potentiometer and the its PIDcontroller. Easier to edit if you put it here

//Multiplier to get meaningful value. A number can be put here
const int SPT_Range 	= 0;
//Quote "offset added to the scaled value to control the 0 value
const int SPT_Offset 	= 0;

const int SPT_Kp 		= 0;//Proportional
const int SPT_Ki		= 0 ;//Intergral
const int SPT_Kd		= 0;//Derivative

const int SPTMotorMin	= -1;//Min Motor speed
const int SPTMotorMax	= 1;// Max motor speed

const int SPTDeliveryPosition 	= 0;//Position has NOT been decided
const int SPTFeederPosition		= 0;//Position has NOT been decided

SPT::SPT() :
		Subsystem("SPT")
{
	SPTShoulderMotor = new Victor(SPTShoulderMotor_Channel);

	SPTPot = new AnalogPotentiometer(SPTPot_Channel, SPT_Range, SPT_Offset);
							//		 ^^Channel in RobotMap

	//Format for declaring PIDControllers (Kp value, Ki value, Kd value, the input source, the output source)
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
	SPTShoulderMotor -> Set(-.5 * ShoulderChangeValue); //Why -0.5?? KJM
															// ^^Jason's response, just sounds like a good number
															// It's negative because up/forward is negative on the controls
															// but up/forward in real life is positive
}

//This function sets the shoulder motor to a certain speed
//The waits a while and stops the motor at the correct angle
//The wait amount is guess and checked.
void SPT::MoveToDeliveryPosition(){
	//Sets the min and max speed the motor of that the SPT has
	SPTPotPID -> SetOutputRange(SPTMotorMin, SPTMotorMax);
	SPTPotPID -> SetSetpoint(SPTDeliveryPosition);
	SPTPotPID -> Enable();
}

//Same thing as MoveToDeliveryPosition but the point where it goes to is the InfeederPosition
void SPT::MoveToInfeederPosition(){
	SPTPotPID -> SetOutputRange(SPTMotorMin, SPTMotorMax);
	SPTPotPID -> SetSetpoint(SPTFeederPosition);
	SPTPotPID -> Enable();
}
