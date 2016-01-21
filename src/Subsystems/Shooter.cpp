/*
 * Catapult shooter subsystem for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 */

#include "Shooter.h"
#include "../RobotMap.h"
#include "PIDController.h"

//Sensor parameters
	const float ShooterPotScale		=	0;
	const float ShooterPotOffset	=	0;

	const float PIDMotorMIN			=	0; //MAY BE UPDATED - Made 0-1 so motor can only turn forward
	const float PIDMotorMAX 		=	1;
	const float ShooterKp			=	0; //MUST BE UPDATED - Gains will be tuned
	const float ShooterKi			=	0; //MUST BE UPDATED - Gains will be tuned
	const float ShooterKd			=	0; //MUST BE UPDATED - Gains will be tuned

	const float ShooterResetDwell	=	0;
	const float ShooterFiredSetpoint=	0;
	const float ShooterResetSetpoint=	0;

Shooter::Shooter() :
		Subsystem("Shooter")
{

	ShooterMotor	= new Victor(ShooterMotor_Channel);
	ShooterPot		= new AnalogPotentiometer(ShooterPot_Channel,ShooterPotScale, ShooterPotOffset);
	ShooterPID		= new PIDController(ShooterKp, ShooterKi, ShooterKd, ShooterPot, ShooterMotor);
}

void Shooter::InitDefaultCommand()
{
//	SetDefaultCommand(); //Not sure what/if the default command should be, but we may want a check/reset
}

bool Shooter::Shoot() //Shoots the ball
  {
	ShooterPID	-> SetContinuous(); //This should tell the PID max and min are the same point
	ShooterPID	->	SetOutputRange(PIDMotorMIN, PIDMotorMAX);
	ShooterPID	->	SetSetpoint(ShooterFiredSetpoint);
	ShooterPID	->	Enable();
	Wait(ShooterResetDwell);
	ShooterPID	->	SetSetpoint(ShooterResetSetpoint);
	return TRUE;
/* Original design - may remove the loop
 * Loop
 * Check encoder is at its initial set point (cocked - constant)
 * if not at cocked, reverse until at cocked
 * else move to next set point (fired - constant), wait (wait time constant), and BREAK out of loop
 * forward to cocked set point
 * end
 */

  }

  void Shooter::Override(double Input)
  {
/*
 * Forward and reverse based on controller input - for jams or other unforeseen situations
 */
	  ShooterMotor	->	Set(Input);

  }

