/*
 * Drive command for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * Vi = Ao * (sqrt(5 * (((Qc/Po)+1)^(2/7)-1)))
 */

#include "Commands/XboxMove.h"
#include "RobotMap.h"
//#include "SmartDashboard/SmartDashboard.h"

const double Thresh		=	0.1; //Set Dead Zone threshold for thumbstick so small movements don't mess things up

XboxMove::XboxMove()
{
	//Declares required subsystems
	Requires(drivebase);

}

// Called just before this Command runs the first time
void XboxMove::Initialize()
{
	drivebase	-> Reset();
//	drivebase->Stop();
}

// Called repeatedly when this Command is scheduled to run
void XboxMove::Execute()
{
	double 	Slew       =	oi	->	ReadXboxLeftStickX();
	double 	Throttle 	=	oi	->	GetRightTrigger();
	double 	Reverse 	=	oi	->	GetLeftTrigger();
	bool 	Precision	=	oi	->	GetPrecision();
	bool 	Brake		=	oi	->	GetBrake();
	bool 	Turn		= 	oi	->	GetButtonB();
	
	double Right,Left, Sensitivity;

	if (Precision) { //Sets drive precision based on RobotMap and Precision Mode
		Sensitivity	=	Drive_Sensitivity_Precise;
	} else {
		Sensitivity	=	Drive_Sensitivity_Default;
	}
	// -----Begin block of spin in place code
		if (Brake){		//brake, Bracket level 1
			Left = 0;
			Right = 0;
			} else if(!Turn){ 	//drive normally, end bracket L1, new bracket L1
			//else
				if (Slew > Thresh){	//If Slew is positive (Thumbstick pushed right), go Right, new bracket L2
					Left = (Throttle - Reverse) * Sensitivity;			//Send Left full power
					Right = (Throttle - Reverse) * Sensitivity * (1 - Slew);	//Send Right partial power, tempered by how hard the thumbstick is being pushed
					} else if (Slew < (-1 * Thresh)){	//If Slew is negative (Thumbstick pushed left), go Left, end bracket L2, new bracket L2 ***020516 KJM - added an else here.  May be unnecessary
						Left = (Throttle - Reverse) * Sensitivity * (1 + Slew);		//Send Left partial power, tempered by how hard thumbstick is being pushed left
						Right = (Throttle - Reverse) * Sensitivity; 			//Send Right full power
							} else //if (Slew < Thresh && Slew > (-1 * Thresh))
								{
									Left = (Throttle - Reverse) * Sensitivity;
									Right = (Throttle - Reverse) * Sensitivity;
								}//end bracket L2
			} else //if (turn)
				{	//drive turning end bracket L1, new bracket L1
				if (Slew > Thresh){	//Spin in place, if Slew is positive (Thumbstick pushed right), spin right, new bracket L2
					Left = Sensitivity * Slew * .5;					//Left partial power, tempered by thumbstick
					Right = Sensitivity * Slew * -1 * .5;				//Right partial reverse, tempered by thumbstick
				} else if (Slew < (-1 * Thresh)){	//Spin in place, if Slew is negative (Thumbstick pushed left), spin left, end bracket L2, new bracket L2 ***020516 KJM - added an else here.  May be unnecessary
					Left = Sensitivity * Slew * -1 * .5;					//Left partial reverse, tempered by thumbstick
					Right = Sensitivity * Slew * .5;					//Right partial forward, tempered by thumbstick
				}//end bracket L2
 
			}//end bracket L1
	//------End block of spin in place code
 
	/*	SmartDashboard::PutNumber("Throttle",Throttle);
		SmartDashboard::PutNumber("Reverse",Reverse);
		SmartDashboard::PutNumber("Slew",Slew);
		SmartDashboard::PutNumber("Left",Left);
		SmartDashboard::PutNumber("Right",Right);
		SmartDashboard::PutBoolean("Turn",turn);
		SmartDashboard::PutBoolean("Precision",Precision);
		SmartDashboard::PutBoolean("Brake",Brake);
	*/
	drivebase        -> Drive(Left, Right, Encoder_Conversion_To_Inches_Constant);
}

// Make this return true when this Command no longer needs to run execute()
bool XboxMove::IsFinished()
{

	return false;
}

// Called once after isFinished returns true
void XboxMove::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void XboxMove::Interrupted()
{

}
