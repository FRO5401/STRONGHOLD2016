/*
 * Catapult targeting for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 */

#include <Commands/AutoLaunch.h>
#include "RobotMap.h"
#include "../Target.h"
const int LightFlashes	= 5;
const float LaunchPrecision = 0.25;


AutoLaunch::AutoLaunch()
{
	RING_HUE_RANGE = RING_HUE_RANGE_d;	//Default hue range for ring light R
	RING_SAT_RANGE = RING_SAT_RANGE_d;	//Default saturation range for ring light G
	RING_VAL_RANGE = RING_SAT_RANGE_d;	//Default value range for ring light B
	ImgLatency = 0;
	Area = Area_d;
	Aspect = Aspect_d;
	Angle 		= -180;
	Requires(waterytart);
	Requires(relaysys);
	Requires(spt);
	Requires(shooter);
	Finish = false;
}

void AutoLaunch::Initialize() {
  Finish = false;
};

void AutoLaunch::Execute(){
	/*
	 * This will do image processing, to locate the target and properly move the robot to the launch site
	 * Then it will set a bool flag Lock to indicate target lock
	 * When finished, it will kick off the launch command
	 */
	SmartDashboard::PutBoolean("LAUNCH ACTIVATED", false);
	SmartDashboard::PutBoolean("LAUNCH ABORTED", false);
	Angle = -180;
	//Update threshold values from SmartDashboard. For performance reasons it is recommended to remove this after calibration is finished.
/*	RING_HUE_RANGE.minValue = SmartDashboard::GetNumber("Tote hue min", RING_HUE_RANGE.minValue);
	RING_HUE_RANGE.maxValue = SmartDashboard::GetNumber("Tote hue max", RING_HUE_RANGE.maxValue);
	RING_SAT_RANGE.minValue = SmartDashboard::GetNumber("Tote sat min", RING_SAT_RANGE.minValue);
	RING_SAT_RANGE.maxValue = SmartDashboard::GetNumber("Tote sat max", RING_SAT_RANGE.maxValue);
	RING_VAL_RANGE.minValue = SmartDashboard::GetNumber("Tote val min", RING_VAL_RANGE.minValue);
	RING_VAL_RANGE.maxValue = SmartDashboard::GetNumber("Tote val max", RING_VAL_RANGE.maxValue);
	Area					 = SmartDashboard::GetNumber("Target Area min %", Area);
	Aspect					 = SmartDashboard::GetNumber("Target Aspect Ratio", Aspect);//Unused right now
*/
	relaysys	->TurnOn(); //Activates ring light
	Angle = waterytart	->	Search(RING_HUE_RANGE, RING_SAT_RANGE, RING_VAL_RANGE, Area, Aspect, ImgLatency); //Searches for the target, returns the angle off center
    if (fabs(Angle) < AngleRange){	//Anglerange part of Target.h, if the angle is in range, begin launch sequence
    	SmartDashboard::PutBoolean("LAUNCH ACTIVATED", true);
    	float Error = drivebase -> AutoTurnAngle(Angle, LaunchPrecision); //Error is the final angle error
    	SmartDashboard::PutNumber("Auto Launch Angle Error", Error);
    	spt 	-> ClearShooterPathPosition(); //Move the SPT out of the way of the catapult
    	shooter -> Shoot(); //FIRE!!
//    	relaysys -> ShootLights(LightFlashes);
    } else {
    	SmartDashboard::PutBoolean("LAUNCH ABORTED", true);
    }
};

bool AutoLaunch::IsFinished()
{
	return true;
}

void AutoLaunch::End(){
	relaysys	->TurnOff();
	waterytart	->	Stop();
	shooter -> Reset();
}

void AutoLaunch::Interrupted(){};
