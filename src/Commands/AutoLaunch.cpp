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
const float LaunchAngleThreshold = 2;
const double AutoTurnPrecision = 0.65;
const double AutoTurnSpeed	= 0.95;

AutoLaunch::AutoLaunch()
{/*
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
	Requires(drivebase);
	Finish = false;
	Launching = false;
	CurrentAngle = 0;
	DesiredTurnAngle = 0;
	InitAngle = 0;
*/}

void AutoLaunch::Initialize() {/*
  Finish = false;
	Launching = false;
  CurrentAngle = 0;
  DesiredTurnAngle = 0;
  drivebase -> Stop();
  InitAngle = drivebase -> ReportGyro();
*/}

void AutoLaunch::Execute(){/*
	/*
	 * This will do image processing, to locate the target and properly move the robot to the launch site
	 * Then it will set a bool flag Lock to indicate target lock
	 * When finished, it will kick off the launch command
	 */
			//Update threshold values from SmartDashboard. For performance reasons it is recommended to remove this after calibration is finished.
/*	SmartDashboard::PutBoolean("LAUNCH ACTIVATED", false); //TODO extra comment start here due to one above
	SmartDashboard::PutBoolean("LAUNCH ABORTED", false);
	if(!Launching){
		Angle = -180;
		RING_HUE_RANGE.minValue = SmartDashboard::GetNumber("Tote hue min", RING_HUE_RANGE.minValue);
		RING_HUE_RANGE.maxValue = SmartDashboard::GetNumber("Tote hue max", RING_HUE_RANGE.maxValue);
		RING_SAT_RANGE.minValue = SmartDashboard::GetNumber("Tote sat min", RING_SAT_RANGE.minValue);
		RING_SAT_RANGE.maxValue = SmartDashboard::GetNumber("Tote sat max", RING_SAT_RANGE.maxValue);
		RING_VAL_RANGE.minValue = SmartDashboard::GetNumber("Tote val min", RING_VAL_RANGE.minValue);
		RING_VAL_RANGE.maxValue = SmartDashboard::GetNumber("Tote val max", RING_VAL_RANGE.maxValue);
		Area					 = SmartDashboard::GetNumber("Target Area min %", Area);
		Aspect					 = SmartDashboard::GetNumber("Target Aspect Ratio", Aspect);//Unused right now
		relaysys	->TurnOn();
		Angle = waterytart	->	Search(RING_HUE_RANGE, RING_SAT_RANGE, RING_VAL_RANGE, Area, Aspect, ImgLatency);
	    if (fabs(Angle) < AngleRange){
	    	Launching = true;
	    	DesiredTurnAngle = Angle;
	    } else {
	    	Finish = true;
	    	Launching = false;
	    	SmartDashboard::PutBoolean("NO TARGET", true);
	    }
	} else {
    	Launching = true;
    	SmartDashboard::PutBoolean("LAUNCH ACTIVATED", true);
//    	spt 	-> ClearShooterPathPosition();

    	//Not using ReportGyro as it possibly doesn't work; if this code works, try ReportGyro()
//    	CurrentAngle = 0; Initializes in the constructor.

    	if (fabs(DesiredTurnAngle) <= LaunchAngleThreshold){
//    		std::cout << "DesiredTurnAngle too small!!!\n";
        	bool DriverAbort = oi -> GetXboxRightStickButton();
        	bool OpAbort = oi -> GetMOHLeftStickButton();
        	if(!DriverAbort  && !OpAbort){
        	shooter	->	Shoot();
        		if (shooter -> ReportEncoder() < ShooterFiredPosition){
        			Finish = false;
        //	relaysys -> ShootLights(2);
        		} else {
        			Finish = true;
        		}
        	} else { Finish = true;
     //   	relaysys -> ShootLights(LightFlashes);}
        	}
    	}
    	else {
    			if ((DesiredTurnAngle > 0) && (CurrentAngle < (fabs(DesiredTurnAngle) - LaunchAngleThreshold))){
    				drivebase -> Drive(AutoTurnSpeed * AutoTurnPrecision, -AutoTurnSpeed * AutoTurnPrecision);
    			} else if (DesiredTurnAngle < 0 &&(CurrentAngle > LaunchAngleThreshold - fabs(DesiredTurnAngle)) {
    				drivebase -> Drive(-AutoTurnSpeed * AutoTurnPrecision, AutoTurnSpeed * AutoTurnPrecision);
    			} else { //error or exactly 0
    				std::cout << "AutoTurnAngle Error!!!\n";
    				Finish = true;
    			}
    		CurrentAngle = drivebase -> ReportGyro() - InitAngle;

    	}

//    	drivebase -> Stop(); //Stop motors for autonomous
//    	return (0); //not sure what return does


//    	float Error = drivebase -> AutoTurnAngle(Angle, LaunchPrecision);
//    	SmartDashboard::PutNumber("Auto Launch Angle Error", Error);
}
*/}

bool AutoLaunch::IsFinished()
{
	return true;//Finish;
}

void AutoLaunch::End(){
	relaysys	->TurnOff();
	waterytart	->	Stop();
	shooter -> Reset();
	drivebase -> Stop();
}

void AutoLaunch::Interrupted(){
	relaysys	->TurnOff();
	waterytart	->	Stop();
	shooter -> Reset();
	drivebase -> Stop();

};
