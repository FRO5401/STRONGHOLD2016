#include "ShooterReset.h"

const double ShooterCockedPosition = 359;

ShooterReset::ShooterReset()
{
	Requires(shooter);
	ResetComplete = true;
}

// Called just before this Command runs the first time
void ShooterReset::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void ShooterReset::Execute()
{
	shooter	->	Shoot();
	if ((shooter -> ReportEncoder()) < ShooterCockedPosition){
	ResetComplete = false;
	std::cout << ("Rsetting\n");
	//	relaysys -> ShootLights(2);
	} else {
		ResetComplete = true;
		std::cout << ("Rset finished\n");
		}

}

// Make this return true when this Command no longer needs to run execute()
bool ShooterReset::IsFinished()
{
	return ResetComplete;
}

// Called once after isFinished returns true
void ShooterReset::End()
{
	shooter -> Stop();
	std::cout << ("Rset stopping shooter\n");

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ShooterReset::Interrupted()
{
	shooter -> Stop();
	std::cout << ("Rset interrupted\n");

}
