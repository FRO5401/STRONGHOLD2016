/*
 * Watery Tart subsystem for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * Based off 2015 Vision Retro Sample
 * You can't expect to wield supreme executive power just because some watery tart threw a sword at you.
 */

#include "WateryTart.h"
#include "../RobotMap.h"
#include "Commands/LockTarget.h"
#include "SmartDashboard/SmartDashboard.h"
#include "LiveWindow/LiveWindow.h"

//#include <opencv2/opencv.hpp>
#include <math.h>
#include <ctime>

WateryTart::WateryTart() :
		Subsystem("WateryTart")
{
//Motor and sensor declarations here

}

void WateryTart::InitDefaultCommand()
{
//	SetDefaultCommand(new LockTarget());
}

void WateryTart::Search()
  {
	/* INTENT:
	 * Upon the press of a button, a command will invoke this function to check the image for the scoring U, and evaluate whether we have a shooting vector
	 * It will return a rumble to the controller and splash a green box on the dashboard
	 * Ideally, this will take place on an on board raspberry pi or arduino board, but that is version 2.0
	 */
  }

void WateryTart::Manual()
  {
/*
 * While a button is pressed, this will show a display with a crosshair that will allow manual aiming
 */

  }

 void WateryTart::Stop()
  {
/*
 * Not sure this will be needed but reserving a space for it so that we can clear image, or reinitialize variables, or anything associated with stopping
 */

  }

  void WateryTart::Reset()
  {

/*
 * Not sure what thsi might do or what might trigger it, but want to see if there's any kind of clear image cache or something
 */

  }

