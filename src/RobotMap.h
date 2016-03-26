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
const double Latency = 0.001;

//const double Encoder_Conversion_To_Inches_Constant = 1; No longer needed. Equivalent is in DriveBase
/***********************
 * End Global Variables
 ***********************/

/****************
 * Controllers
 **************/
const int XboxController_Channel	= 1;//Controller for drivebase
const int MedalOfHonorController_Channel = 2;//Controller for operator

const int LBumper_ID	=	5; //Button channels
const int RBumper_ID	=	6;
const int XboxB_ID		=	2;
const int XboxA_ID		=	1;
const int XboxX_ID		=	3;
const int Start_ID		=	8;
const int XboxR3_ID		=	10;
const int Back_ID		=	7;
const int XboxL3_ID		=	9;
const int MOHStartID	=	10;
const int MOHL3_ID		= 	11;

/****************
 * End Controllers
 **************/

/****************
* Pnuematics
**************/
/* Pneumatics are out of design now
//ID of solenoid control
const int SolenoidCAN_ID	= 0;

//Drive gear shift
const int Shift_LeftFwd		= 0;
const int Shift_LeftRev		= 1;
const int Shift_RightFwd	= 2;
const int Shift_RightRev	= 3;

//PTO clutch
const int ScaleEngageFwd_Channel  =	4;
const int ScaleEngageRev_Channel	 =	5;
const int DriveDisengageFwd_Channel	=	6;
const int DriveDisengageRev_Channel	=	7;

//Short hook extender
const int ShortHookFwd_Channel		=	11;
const int ShortHookRev_Channel		=	12;
*/
/****************
 * End Pnuematics
 **************/

/****************
 * Drive Motors
 **************/
//Motor location may change
const int LeftMotor1	= 2;//Locations of Motors, check under PWM of roboRIO
const int LeftMotor2	= 3;
const int RightMotor1	= 0;//and the wires connecting the roboRIO to motors
const int RightMotor2	= 1;
/*******************
 * End Drive Motors
 *******************/

/************
 * Other Motors (PWM)
 ***********/
const int SPTShoulderMotor_Channel			= 5;//Current as of 021616 //5

//Feeder Motors the outer and inner one
const int FeederOuterFasterMotor_Channel	= 6;//Current as of 021616
const int FeederInnerSlower_Channel			= 7;//Current as of 021616

const int HookShoulderMotor_Channel			= 9;

//Removed Until Further Notice 31816
//const int ShooterMotor_Channel				= 9;

const int RightScimitar_Channel				= 8; //10
const int LeftScimitar_Channel				= 4; //11
/************
 * End Other Motors
 ***********/
 
/************
 * Other Stuff
 ***********/
const int LightRing_Channel					= 0;
const int CarriageLights_Channel			= 1;
/************
 * End Other Stuff
 ***********/

/************
 * Sensor Channels
 ***********/
//Removed Until Further Notice 31816
//const int ShooterSwitch_Channel 	= 0;			//MUST BE UPDATED
const int HookShoulderPot_Channel	= 0;	//MUST BE UPDATED
const int SPTPot_Channel 		= 1;//MUST BE UPDATED SPT potentiometer channel, under Analogs

//Encoder DIO Channels
const int Enc_Left_A 	= 4; //XXX Should be 6 //not plugged in
const int Enc_Left_B 	= 5; //XXX Should be 7 //not plugged in
const int Enc_Right_A 	= 2;
const int Enc_Right_B 	= 3;
const int Enc_SPT_Loc_A = 0;
const int Enc_SPT_Loc_B = 1;

//const int Enc_Shooter_A = 4;
//const int Enc_Shooter_B = 5;
//TODO validate these

const int Left_Enc_Scimitar_A = 8; //was 7
const int Left_Enc_Scimitar_B = 9; //was 8
const int Right_Enc_Scimitar_A = 6;
const int Right_Enc_Scimitar_B = 7;

//LimitSwitch Channels
const int RightFarLimit_Channel   = 10;
const int RightCloseLimit_Channel = 11;
const int LeftFarLimit_Channel    = 13;
const int LeftCloseLimit_Channel  = 12;

/************
 * End Sensor Channels
 ***********/

#endif
