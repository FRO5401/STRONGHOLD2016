/*
 * Hook shoulder subsystem for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * Subsystem turns robot into a newt.
 */

#include "HookShoulder.h"
#include "../RobotMap.h"
#include "PIDController.h"
#include "Commands/HookShoulderUpDown.h"

//Parameters for Potentiometer and the its PIDcontroller. Easier to edit if you put it here

//Multiplier to get meaningful value. A number can be put here
const double HookShoulder_Range 	= 0;
//Quote "offset added to the scaled value to control the 0 value
const double HookShoulder_Offset 	= 0;

//NO LONGER USED
const double HookShoulder_Kp 		= 0;//Proportional
const double HookShoulder_Ki		= 0;//Intergral
const double HookShoulder_Kd		= 0;//Derivative

const double HookShoulderMotorMin	= -1;//Min Motor speed
const double HookShoulderMotorMax	= 1;// Max motor speed
const double HookShoulderSensitivity = 0.5;

//The following WILL CHANGE
const double MaxPosition			= 0;//The maximum position for the hook shoulder
const double MinPosition			= 0;//the minimum position for the hook shoulder

HookShoulder::HookShoulder() :
		Subsystem("HookShoulder")
{
	HookShoulderMotor = new Victor(HookShoulderMotor_Channel);

	HookShoulderPot = new AnalogPotentiometer(HookShoulderPot_Channel, HookShoulder_Range, HookShoulder_Offset);
							//		 			^^Channel in RobotMap

	//Format for declaring PIDControllers (Kp value, Ki value, Kd value, the input source, the output source)
	//Read Control Theory from http://www.chiefdelphi.com/media/papers/1823
//	HookShoulderPID = new PIDController(HookShoulder_Kp, HookShoulder_Ki, HookShoulder_Kd, HookShoulderPot, HookShoulderMotor);

}

void HookShoulder::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new HookShoulderUpDown());
}

//This function sets the shoulder motor of SPT to a certain direction between up and down
void HookShoulder::UpAndDown(double HookShoulderChangeValue, bool Override){
/*Add a constant above, and make this conditional on being within a max/min reading on the Pot.
 * This is to keep it from going above a certain angle for rules and below a certain angle so it doesn't
 * keep running once it gets into the robot
 */
	Override = TRUE; //TODO Remove once shoulder is tested and override is ready to test
	double CurrentPosition = ReportAngle();
	if(!Override)
	{
		//Zero out the change if angle is at its upper limit and trying to increase, <0 = UP?
		HookShoulderChangeValue = ((HookShoulderChangeValue < 0) && (CurrentPosition >= MaxPosition)) ? 0 : HookShoulderChangeValue;
		//Zero out the change if angle is at its lower limit and trying to decrease
		HookShoulderChangeValue = ((HookShoulderChangeValue > 0) && (CurrentPosition <= MinPosition)) ? 0 : HookShoulderChangeValue;
	}
	//Returns the Angle the HookShoulder is at to the Dashboard
	SmartDashboard::PutNumber("HookShoulderPot", HookShoulderPot -> Get());
	HookShoulderMotor -> Set(0);//TODO Make this useful
}

double HookShoulder::ReportAngle(){
	//Sets the min and max speed the motor of that the SPT has
	return HookShoulderPot -> Get();
}

void HookShoulder::StopHookShoulder(){
	HookShoulderMotor -> Set(0);
}



