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
#include "Commands/UpAndDownInfeeder.h"

//Parameters for Potentiometer and the its PIDcontroller. Easier to edit if you put it here

//Multiplier to get meaningful value. A number can be put here
double SPT_Range 	= -1376.15;
//Quote "offset added to the scaled value to control the 0 value
double SPT_Offset 	= 638.073;

double SPT_Kp 		= 0;//Proportional
double SPT_Ki		= 0 ;//Intergral
double SPT_Kd		= 0;//Derivative

double SPTMotorMin	= -1;//Min Motor speed
double SPTMotorMax	= 1;// Max motor speed

double SPTDeliveryPosition 	= 0;//Position has NOT been determined
double SPTFeederPosition		= 0;//Position has NOT been determined

double SPTPrecision = 0.2; //Set precision very high while PID and stop points are not defined

SPT::SPT() :
		Subsystem("SPT")
{
	SPTShoulderMotor = new Victor(SPTShoulderMotor_Channel);

	SPTPot = new AnalogPotentiometer(SPTPot_Channel, SPT_Range, SPT_Offset);
							//		 ^^Channel in RobotMap

	//Format for declaring PIDControllers (Kp value, Ki value, Kd value, the input source, the output source)
	//Read Control Theory from http://www.chiefdelphi.com/media/papers/1823
	SPTPotPID = new PIDController(SPT_Kp, SPT_Ki, SPT_Kd, SPTPot, SPTShoulderMotor);

//Makes the SPT subsystem constantly get the values of the global variables off the SmartDashboard
//Thus if operater makes change to values, the code will automatically input that value.
	SmartDashboard::PutNumber("SPT Range", SPT_Range);
	SmartDashboard::PutNumber("SPT Offset", SPT_Offset);
	SmartDashboard::PutNumber("SPT Kp", SPT_Kp);
	SmartDashboard::PutNumber("SPT Ki", SPT_Ki);
	SmartDashboard::PutNumber("SPT Kd", SPT_Kd);
	SmartDashboard::PutNumber("SPTMotorMin", SPTMotorMin);
	SmartDashboard::PutNumber("SPTMotorMax", SPTMotorMax);
	SmartDashboard::PutNumber("SPTDeliveryPosition", SPTDeliveryPosition);
	SmartDashboard::PutNumber("SPTFeederPosition", SPTFeederPosition);
}

void SPT::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new UpAndDownInfeeder());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.


//This function sets the shoulder motor of SPT to a certain direction between up and down
void SPT::UpAndDown(double ShoulderChangeValue){
	SPTShoulderMotor -> Set(SPTPrecision * ShoulderChangeValue); 
	SmartDashboard::PutNumber("SPTUpDown", ShoulderChangeValue);
	SmartDashboard::PutNumber("SPTPot", SPTPot ->Get());
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
