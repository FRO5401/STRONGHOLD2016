/*
 * Long hook subsystem for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * Extends long enough to scale the castle
 * Oh but if I went 'round sayin' I was Emperor, just because some
 * moistened bint lobbed a scimitar at me, they'd put me away.
 */

#include "Scimitar.h"
#include "../RobotMap.h"

const int ScimitarSpeed	=	0.9;

Scimitar::Scimitar() :
		Subsystem("Scimitar")
{
	Lobber 	= new Victor(Lobber_Channel);

}

void Scimitar::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
};

void Scimitar::Extend(bool Fwd)
{
	if (Fwd) {
		  Lobber 	-> Set(ScimitarSpeed);
	} else Lobber 	-> Set(-1 * ScimitarSpeed);
}
