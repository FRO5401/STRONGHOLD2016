/*
 * Hook shoulder subsystem for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * Subsystem turns robot into a newt.
 */

#include "HookShoulder.h"
#include "../RobotMap.h"
#include "PIDController.h"

//Parameters for Potentiometer and the its PIDcontroller. Easier to edit if you put it here

//Multiplier to get meaningful value. A number can be put here
const int HookShoulder_Range 	= 0;
//Quote "offset added to the scaled value to control the 0 value
const int HookShoulder_Offset 	= 0;

const int HookShoulder_Kp 		= 0;//Proportional
const int HookShoulder_Ki		= 0 ;//Intergral
const int HookShoulder_Kd		= 0;//Derivative

const int HookShoulderMotorMin	= -1;//Min Motor speed
const int HookShoulderMotorMax	= 1;// Max motor speed

//The following WILL CHANGEs
const int MaxPosition			= 0;//The maximum position for the hook shoulder
const int MinPosition			= 0;//the minimum position for the hook shoulder

HookShoulder::HookShoulder() :
		Subsystem("HookShoulder")
{
	HookShoulderMotor = new Victor(HookShoulderMotor_Channel);

	HookShoulderPot = new AnalogPotentiometer(HookShoulderPot_Channel, HookShoulder_Range, HookShoulder_Offset);
							//		 ^^Channel in RobotMap

	//Format for declaring PIDControllers (Kp value, Ki value, Kd value, the input source, the output source)
	//Read Control Theory from http://www.chiefdelphi.com/media/papers/1823
	HookShoulderPID = new PIDController(HookShoulder_Kp, HookShoulder_Ki, HookShoulder_Kd, HookShoulderPot, HookShoulderMotor);

}

void HookShoulder::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

//This function sets the shoulder motor of SPT to a certain direction between up and down
void HookShoulder::UpAndDown(double HookShoulderChangeValue){
/*Add a constant above, and make this conditional on being within a max/min reading on the Pot.
 * This is to keep it from going above a certain angle for rules and below a certain angle so it doesn't
 * keep running once it gets into the robot
 */
	double Position = HookShoulderMotor -> Get();
	if(Position <= MaxPosition && Position >= MinPosition)
	{
		HookShoulderMotor -> Set(-.5 * HookShoulderChangeValue); //Why -0.5?? carried from SPT KJM
	}
	else
	{
		HookShoulderMotor -> Set(0);
	}
}

void HookShoulder::MoveToPosition(double DesiredPosition){
	//Sets the min and max speed the motor of that the SPT has
	HookShoulderPID -> SetOutputRange(HookShoulderMotorMin, HookShoulderMotorMax);
	HookShoulderPID -> SetSetpoint(DesiredPosition);
	HookShoulderPID -> Enable();
}
/*
void HookShoulder::MoveToBumperPosition(){
	HookShoulderPID -> SetOutputRange(HookShoulderMotorMin, HookShoulderMotorMax);
	HookShoulderPID -> SetSetpoint(BumperPosition);
	HookShoulderPID -> Enable();

}*/
