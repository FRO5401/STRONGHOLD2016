/*
 * Catapult targeting for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 */

#include <Commands/LockTarget.h>
#include "RobotMap.h"
#include "../Target.h"

LockTarget::LockTarget()
{
	RING_HUE_RANGE = RING_HUE_RANGE_d;	//Default hue range for ring light R
	RING_SAT_RANGE = RING_SAT_RANGE_d;	//Default saturation range for ring light G
	RING_VAL_RANGE = RING_VAL_RANGE_d;	//Default value range for ring light B
	ImgLatency = 0.5;
	Area = Area_d;
	Aspect = Aspect_d;
	Angle 		= -180;
	Requires(waterytart);
	Requires(relaysys);
}
void LockTarget::Initialize() {

};

void LockTarget::Execute(){
/*
 * This will do image processing, to locate the target and properly move the robot to the launch site
 * Then it will set a bool flag Lock to indicate target lock
 * When finished, it will kick off the launch command
 */
		//Update threshold values from SmartDashboard. For performance reasons it is recommended to remove this after calibration is finished.
	RING_HUE_RANGE.minValue = SmartDashboard::GetNumber("Tote hue min", RING_HUE_RANGE.minValue);
	RING_HUE_RANGE.maxValue = SmartDashboard::GetNumber("Tote hue max", RING_HUE_RANGE.maxValue);
	RING_SAT_RANGE.minValue = SmartDashboard::GetNumber("Tote sat min", RING_SAT_RANGE.minValue);
	RING_SAT_RANGE.maxValue = SmartDashboard::GetNumber("Tote sat max", RING_SAT_RANGE.maxValue);
	RING_VAL_RANGE.minValue = SmartDashboard::GetNumber("Tote val min", RING_VAL_RANGE.minValue);
	RING_VAL_RANGE.maxValue = SmartDashboard::GetNumber("Tote val max", RING_VAL_RANGE.maxValue);
	Area					 = SmartDashboard::GetNumber("Target Area min %", Area);
	Aspect					 = SmartDashboard::GetNumber("Target Aspect Ratio", Aspect);//Unused right now
	Angle = -180;
	relaysys	->TurnOn();
	Angle = waterytart	->	Search(RING_HUE_RANGE, RING_SAT_RANGE, RING_VAL_RANGE, Area, Aspect, ImgLatency);
	if (fabs(Angle) < AngleRange){
	   	oi	->	SendMOHRumble(2);
	   	SmartDashboard::PutBoolean("TARGET ACQUIRED", true);
	} else {
	SmartDashboard::PutBoolean("TARGET ACQUIRED", false);
	}
};

bool LockTarget::IsFinished()
{
	return true;
}

void LockTarget::End(){
	relaysys	->TurnOff();
	waterytart	->	Stop();

}

void LockTarget::Interrupted(){};
