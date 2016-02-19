/*
 * Catapult shooter subsystem for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * This subsystem farts in your general direction!
 */

#include "Shooter.h"
#include "../RobotMap.h"
#include "PIDController.h"
#include <Commands/ShooterOverride.h>

//Sensor parameters
const double FwdSpeed 			= 0.5;
const double ShooterResetDwell	= 0.01;
//Encoder Constant
//Variable to convert pulse to degrees
double ShooterDistancePerPulseValue = 0;
//The degrees from starting position for the angle to shoot
double ShooterFiredPosition = 0;
double ShooterCockedPosition = 0;

Shooter::Shooter() :
		Subsystem("Shooter")
{

	ShooterMotor	= new Victor(ShooterMotor_Channel);
	ShooterSwitch	= new DigitalInput(ShooterSwitch_Channel);
	//New Stuff 020816
	ShooterEnc		= new Encoder(Enc_Shooter_A, Enc_Shooter_B, true, Encoder::k1X);
	SmartDashboard::PutNumber("Distance Per Pulse Value in Degrees for Shooter", ShooterDistancePerPulseValue);
	SmartDashboard::PutNumber("Position of Shooter After Being Fired", ShooterFiredPosition);
	SmartDashboard::PutNumber("Position of Shooter Being Cocked", ShooterCockedPosition);
	ShooterEnc -> SetDistancePerPulse(ShooterDistancePerPulseValue);
}

void Shooter::InitDefaultCommand()
{
	SetDefaultCommand(new ShooterOverride()); //Not sure what/if the default command should be, but we may want a check/reset
}

void Shooter::Shoot() //Shoots the ball
{
	while((ShooterEnc -> GetDistance()) != ShooterCockedPosition)
	{
		//Automatically moves the motor when function is called
		ShooterMotor	->	Set(FwdSpeed);
		//When the limit switch is hit the encoder resets and starts to run forward
		if(ShooterSwitch -> Get())
		{
			ShooterEnc -> Reset();
			while((ShooterEnc -> GetDistance()) != ShooterCockedPosition)
			{
				if((ShooterEnc -> GetDistance()) < ShooterCockedPosition)
				{
					ShooterMotor -> Set(FwdSpeed);
				}
				if((ShooterEnc -> GetDistance()) > ShooterCockedPosition)
				{
					ShooterMotor -> Set(-FwdSpeed);
				}
			}
		}
//	Wait(ShooterResetDwell);  //Inserting a small dwell, just to make sure that it moves forward before terminating
	}
	while((ShooterEnc -> GetDistance()) != ShooterFiredPosition)
	{
		ShooterMotor -> Set(FwdSpeed);
		Wait(ShooterResetDwell);
		ShooterMotor -> Set(0);
	}
/* Original design - may remove the loop
 * Loop
 * Check encoder is at its initial set point (cocked - constant)
 * if not at cocked, reverse until at cocked
 * else move to next set point (fired - constant), wait (wait time constant), and BREAK out of loop
 * forward to cocked set point
 * end
 * Update 020716 Pot not correct for shooter.  must move forward cyclically.  Going forward on command until a limit switch is tripped.
 */
}

void Shooter::Override(double Input)
{
/*
 * Forward and reverse based on controller input - for jams or other unforeseen situations
 */
	ShooterMotor	->	Set(Input);
	SmartDashboard::PutNumber("Shooter Encoder", ShooterEnc ->Get());
}

