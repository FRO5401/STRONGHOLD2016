/*
 * Scale subsystem for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * Subsystem fights with the strength of many men, Sir Scale
 */

#include "Scale.h"
#include "../RobotMap.h"

Scale::Scale() :
		Subsystem("ExampleSubsystem")
{
	ScaleEngage 	=	new DoubleSolenoid(SolenoidCAN_ID, ScaleEngageFwd_Channel, ScaleEngageRev_Channel);
	DriveDisengage 	= 	new DoubleSolenoid(SolenoidCAN_ID, DriveDisengageFwd_Channel, DriveDisengageRev_Channel);

}

void Scale::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}

void Scale::EngageScaleMode()
{
/*
 * This function should pull the drive out of gear and put the scaling in gear
 */
}
void Scale::DisengageScaleMode()
{
/*
 * This function should reverse the engage scale mode
 */
}
