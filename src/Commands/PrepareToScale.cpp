/*
 * Scale subsystem for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * And the Lord spake, saying, "First shalt thou take out the
 * Holy Pin. Then shalt thou count to three, no more, no less.
 * Three shall be the number thou shalt count, and the number of
 * the counting shall be three. Four shalt thou not count, neither
 * count thou two, excepting that thou then proceed to three. Five
 * is right out. Once the number three, being the third number, be
 * reached, then lobbest thou thy Holy Hand Grenade of Antioch
 * towards thy foe, who, being naughty in My sight, shall snuff it
 */

#include "PrepareToScale.h"

PrepareToScale::PrepareToScale()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(scale);
}

// Called just before this Command runs the first time
void PrepareToScale::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void PrepareToScale::Execute()
{
	scale	-> EngageScaleMode();

}

// Make this return true when this Command no longer needs to run execute()
bool PrepareToScale::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void PrepareToScale::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PrepareToScale::Interrupted()
{

}
