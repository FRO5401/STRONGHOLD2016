#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
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


/***********************
 * End Global Variables
 ***********************/

/****************
 * Controllers
 **************/
const int XboxController_Channel	= 1;//Controller for drivebase
const int PSController_Channel	= 0;//Controller for drivebase

const int LBumper_ID	=	6; //Button channels
const int RBumper_ID	=	7;
//const int Start_ID	=	8;

/****************
 * End Controllers
 **************/

/****************
* Pnuematics
**************/
const int pnuOff 			= 0;
const int Shift_LeftFwd		= 0;
const int Shift_LeftRev		= 1;
const int Shift_RightFwd	= 2;
const int Shift_RightRev	= 3;
/****************
 * End Pnuematics
 **************/

/****************
 * Drive Motors
 **************/
//Motor location may change
const int LeftMotor		= 0;//Locations of Motors, check under DIO of roboRIO
const int RightMotor 	= 1;//and the wires connecting the roboRIO to motors
/*******************
 * End Drive Motors
 *******************/
/************
 * Other Motors
 ***********/
const int SPTShoulderMotor_Channel	= 2;	//MUST BE UPDATED
const int ShooterMotor_Channel		= 2;	//MUST BE UPDATED


/************
 * End Other Motors
 ***********/

/************
 * Sensor Channels
 ***********/
const int ShooterPot_Channel = 0;			//MUST BE UPDATED


/************
 * End Sensor Channels
 ***********/



#endif
