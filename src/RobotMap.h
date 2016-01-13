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
/***********************
 * End Global Variables
 ***********************/

/****************
 * Controllers
 **************/
const int XboxController_Channel	= 1;//Controller for drivebase
/****************
 * End Controllers
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
#endif
