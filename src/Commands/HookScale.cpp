/*
 * Scaling command for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * And Saint Attila raised the hand grenade up on high, saying,
 * "O Lord, bless this thy hand grenade, that with it thou mayst blow
 * thine enemies to tiny bits, in thy mercy." And the Lord did grin.
 * And the people did feast upon the lambs, and sloths, and carp, and
 * anchovies, and orangutans, and breakfast cereals, and fruit bats,
 * and large chu..
 */

#include "HookScale.h"

const int ScimitarPosition		= 0;//Position has NOT been calibrated

HookScale::HookScale()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(hookshoulder);
}

// Called just before this Command runs the first time
void HookScale::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void HookScale::Execute()
{

	hookshoulder        -> MoveToPosition(ScimitarPosition);

}

// Make this return true when this Command no longer needs to run execute()
bool HookScale::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void HookScale::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HookScale::Interrupted()
{

}
