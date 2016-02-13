//I think this is a relic and can be deleted

#include "RelayOn.h"

RelayOn::RelayOn()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(relaysys);
}

// Called just before this Command runs the first time
void RelayOn::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RelayOn::Execute()
{
	relaysys	->	TurnOn();

}

// Make this return true when this Command no longer needs to run execute()
bool RelayOn::IsFinished()
{
//		bool ButtonTwo = oi	-> GetPSButtonTwo();
		return true;
}

// Called once after isFinished returns true
void RelayOn::End()
{
	relaysys	->	TurnOff();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RelayOn::Interrupted()
{

}
