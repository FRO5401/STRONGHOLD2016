#include "XboxDriving.h"

XboxDriving::XboxDriving()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(drivebase);
}

// Called just before this Command runs the first time
void XboxDriving::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void XboxDriving::Execute()
{	//Movements will currently be in comments, actual code will come later after finalizing logic
	//Equal signs will be replaced by greater and less thans later
	double LeftMove = oi -> ReadXboxLeftAxisY();
	double RightMove = oi -> ReadXboxRightAxisY();
	if(LeftMove == -1 && RightMove == -1)
	{
		//Move Forward
	}else if(LeftMove == 1 && RightMove == 1)
	{
		//Move Backward
	}else if(LeftMove == -1 && RightMove == 1)
	{
		//Turn Right
	}else if(LeftMove == 1 && RightMove == -1)
	{
		//Turn Left
	}

}

// Make this return true when this Command no longer needs to run execute()
bool XboxDriving::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void XboxDriving::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void XboxDriving::Interrupted()
{

}
