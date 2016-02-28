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
const double FwdSpeed 			= 0.95;
const double ShooterResetDwell	= 1;
//Encoder Constant
//Variable to convert pulse to degrees
double ShooterDistancePerPulseValue = -0.2910;//Tuned in 022816
//The degrees from starting position for the angle to shoot
double ShooterFiredPosition = 85;
double ShooterCockedPosition = 359;

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
	while (ShooterEnc -> GetDistance() < ShooterFiredPosition){
		ShooterMotor -> Set(FwdSpeed);	//Moves the shooter from the cocked position into the fired position
		SmartDashboard::PutNumber("Shooter Encoder", ShooterEnc ->GetDistance());
	}
	ShooterMotor -> Set(0); //Stops the shooter after firing
	Wait(ShooterResetDwell); //Waits just to clear the ball
	while (ShooterEnc -> GetDistance() < ShooterCockedPosition){
		ShooterMotor -> Set(FwdSpeed);
		Wait(Latency);//Sets a small wait to allow other commands to proceed while this is operating
	}
	ShooterMotor -> Set(0);

//	SmartDashboard::PutNumber("Distance Per Pulse Value in Degrees for Shooter", ShooterDistancePerPulseValue);
//	SmartDashboard::PutNumber("Position of Shooter After Being Fired", ShooterFiredPosition);
//	SmartDashboard::PutNumber("Position of Shooter Being Cocked", ShooterCockedPosition);
//	SmartDashboard::PutNumber("Shooter Encoder", ShooterEnc ->GetDistance());
}

void Shooter::Override(double Input)
{
/*
 * Forward and reverse based on controller input - for jams or other unforeseen situations
 */
	ShooterMotor	->	Set(Input);
	SmartDashboard::PutNumber("Shooter Encoder", ShooterEnc ->Get());
}

void Shooter::Reset(){
	ShooterEnc -> Reset();
}
