/*
 * Catapult shooter for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 */

#include "Shooter.h"
#include "../RobotMap.h"
#include "PIDController.h"

Shooter::Shooter() :
		Subsystem("Shooter")
{
	ShooterMotor	= new Victor(ShooterMotor_Channel);
	ShooterEncoder	= new Encoder(Enc_Channel_A,Enc_Channel_B,true,Encoder::k1X);
	ShooterPID		= new PIDController(Kp, Ki, Kd, ShooterEncoder, output);

}

void Shooter::InitDefaultCommand()
{
//	SetDefaultCommand(); //Not sure what/if the default command should be, but we may want a check/reset
}

void Shooter::Shoot() //Shoots the ball
  {
	while () {

	}
	/*
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
 * Forward and reverse based on controller input
 */

  }

