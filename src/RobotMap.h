#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 //test
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//const int LEFTMOTOR = 1;
//const int RIGHTMOTOR = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

/*******************
 * Global Variables
 *******************/
const double MinSensitivityThreshold = 0.1;//Sensitivity is used in driving, so that there is a speed limit
const double MaxSensitivityThreshold = 0.9;//for highest speed and lowest speed
const double Drive_Sensitivity_Default	=	1;
const double Drive_Sensitivity_Precise	=	0.2;

const double Encoder_Conversion_To_Inches_Constant = 1;
/***********************
 * End Global Variables
 ***********************/

/****************
 * Controllers
 **************/
const int XboxController_Channel	= 1;//Controller for drivebase
const int MedalOfHonorController_Channel = 2;//Controller for operator

const int LBumper_ID	=	6; //Button channels
const int RBumper_ID	=	7;
const int XboxB_ID		=	2;
//const int Start_ID	=	8;

/****************
 * End Controllers
 **************/

/****************
* Pnuematics
**************/
//ID of solenoid control
const int SolenoidCAN_ID	= 0;

//Drive gear shift
const int Shift_LeftFwd		= 0;
const int Shift_LeftRev		= 1;
const int Shift_RightFwd	= 2;
const int Shift_RightRev	= 3;

//PTO clutch
const int ScaleEngageFwd_Channel	=	0;	//MUST BE CHANGED
const int ScaleEngageRev_Channel	=	0;	//MUST BE CHANGED
const int DriveDisengageFwd_Channel	=	0;	//MUST BE CHANGED
const int DriveDisengageRev_Channel	=	0;	//MUST BE CHANGED

//Short hook extender
const int ShortHookFwd_Channel		=	0;	//MUST BE CHANGED
const int ShortHookRev_Channel		=	0;	//MUST BE CHANGED

/****************
 * End Pnuematics
 **************/

/****************
 * Drive Motors
 **************/
//Motor location may change
const int LeftMotor1	= 0;//Locations of Motors, check under DIO of roboRIO
const int LeftMotor2	= 0;
const int RightMotor1	= 1;//and the wires connecting the roboRIO to motors
const int RightMotor2	= 3;
/*******************
 * End Drive Motors
 *******************/

/************
 * Other Motors
 ***********/
const int SPTShoulderMotor_Channel			= 4;	//MUST BE UPDATED

//Feeder Motors the outer and inner one
const int FeederOuterFasterMotor_Channel	= 0;//MUST BE UPDATED
const int FeederInnerSlower_Channel			= 0;//MUST BE UPDATED

const int HookShoulderMotor_Channel			= 5;	//MUST BE UPDATED

const int ShooterMotor_Channel				= 6;	//MUST BE UPDATED

const int Lobber_Channel			= 0;	//MUST BE UPDATED

/************
 * End Other Motors
 ***********/

/************
 * Sensor Channels
 ***********/
const int ShooterSwitch_Channel 	= 0;			//MUST BE UPDATED
const int SPTPot_Channel 		= 0;//MUST BE UPDATED SPT potentiometer channel
const int HookShoulderPot_Channel	= 0;	//MUST BE UPDATED

//Encoder DIO Channels
const int Enc_Left_A 	= 0;
const int Enc_Left_B 	= 0;
const int Enc_Right_A 	= 0;
const int Enc_Right_B 	= 0;

const int Enc_Shooter_A = 0;
const int Enc_Shooter_B = 0;
/************
 * End Sensor Channels
 ***********/

/************
 * Gyro
 ***********/
const int gyroChannel = 1;

/************
 * End Gyro
 ***********/
#endif
