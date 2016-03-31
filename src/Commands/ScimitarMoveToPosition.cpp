#include "ScimitarMoveToPosition.h"

const double DistanceThreshold = .125; //inches
const double ScimitarPrecision = .5; //TODO Determine best speed
const double K = .75;

ScimitarMoveToPosition::ScimitarMoveToPosition(double distance) //in inches
{
	// Use Requires() here to declare subsystem dependencies
	Requires(scimitar);
	Finished = true;
	DesiredDistance = distance;
}

// Called just before this Command runs the first time
void ScimitarMoveToPosition::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ScimitarMoveToPosition::Execute()
{
	RightPosition = scimitar -> ReportRightPosition();
	LeftPosition = scimitar -> ReportLeftPosition();

	LeftEncRaw 		= scimitar -> ReportLeftRaw();
	RightEncRaw 	= scimitar -> ReportRightRaw();
	error			= LeftEncRaw - RightEncRaw;

	//Assumes starting position is 0
	if ((LeftPosition > DesiredDistance + DistanceThreshold) || (RightPosition > DesiredDistance + DistanceThreshold)){ //Retract
		Left = 1;
		Right = 1;

		if (error > 0){
			Right = K * Right;
		} else if (error < 0 ){
			Left = K * Left;
		}

		scimitar -> Control(Left * ScimitarPrecision, Right * ScimitarPrecision, false);
	} else if ((LeftPosition < DesiredDistance - DistanceThreshold) || (RightPosition < DesiredDistance - DistanceThreshold)){ //Extend
		Left = -1;
		Right = -1;

		if (error > 0){
			Left = K * Left;
		} else if (error < 0 ){
			Right = K * Right;
		}

		scimitar -> Control(Left * ScimitarPrecision, Right * ScimitarPrecision, false);
	} else {
		Finished = true;
	}

}

// Make this return true when this Command no longer needs to run execute()
bool ScimitarMoveToPosition::IsFinished()
{
	if (scimitar -> ReportAnySwitches())
		return true;

	return Finished;
}

// Called once after isFinished returns true
void ScimitarMoveToPosition::End()
{
	scimitar -> Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScimitarMoveToPosition::Interrupted()
{
	scimitar -> Stop();
}
