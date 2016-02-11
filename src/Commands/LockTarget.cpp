/*
 * Catapult targeting for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 */

#include <Commands/LockTarget.h>
#include "RobotMap.h"
bool Lock;
Range RING_HUE_RANGE;// = {0	, 96};	//Default hue range for ring light R
Range RING_SAT_RANGE;// = {110	, 255};	//Default saturation range for ring light G
Range RING_VAL_RANGE;// = {110	, 255};	//Default value range for ring light B
double ImgLatency;

LockTarget::LockTarget()
{
  Requires(waterytart);
  Requires(relaysys);
}
	void LockTarget::Initialize() {
		Range RING_HUE_RANGE = {0	, 96};	//Default hue range for ring light R
		Range RING_SAT_RANGE = {110	, 255};	//Default saturation range for ring light G
		Range RING_VAL_RANGE = {110	, 255};	//Default value range for ring light B
//		Range RING_HUE_RANGE = {101, 64};	//Default hue range for ring light
//		Range RING_SAT_RANGE = {88, 255};	//Default saturation range for ring light
//		Range RING_VAL_RANGE = {134, 255};	//Default value range for ring light
		ImgLatency = 2;
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
		relaysys	->TurnOn();
		waterytart	->	Search(RING_HUE_RANGE, RING_SAT_RANGE, RING_VAL_RANGE);

	};

	bool LockTarget::IsFinished()
{
//	return Lock;
//		bool ButtonTwo = oi	-> GetPSButtonTwo();
//		return ButtonTwo;
		return true;
}

	void LockTarget::End(){
		relaysys	->TurnOff();
		waterytart	->	Stop();

	}

	void LockTarget::Interrupted(){};
