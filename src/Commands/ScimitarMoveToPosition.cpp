#include "ScimitarMoveToPosition.h"

const double DistanceThreshold = .125; //inches
const double ScimitarPrecision = 1; //TODO Determine best speed
const double K = .75;

ScimitarMoveToPosition::ScimitarMoveToPosition(double distance) //in inches
{
	// Use Requires() here to declare subsystem dependencies
	Requires(scimitar);
	Finished = true;
	DesiredDistance = distance;
	Left = 0;
	Right = 0;
	RightPosition = 0;
	LeftPosition = 0;
	error = 0;
	RightEncRaw = 0;
	LeftEncRaw = 0;
	Override = false;

}

// Called just before this Command runs the first time
void ScimitarMoveToPosition::Initialize()
{
	std::cout << "Scimitar Move To Position Initializing\n";
	Finished = false;

}

// Called repeatedly when this Command is scheduled to run
void ScimitarMoveToPosition::Execute()
{
	RightPosition = scimitar -> ReportRightPosition();
	LeftPosition = scimitar -> ReportLeftPosition();

	LeftEncRaw 		= scimitar -> ReportLeftRaw();
	RightEncRaw 	= scimitar -> ReportRightRaw();
	error			= LeftEncRaw - RightEncRaw;

	Override = oi -> GetMOHButtonTriangle();
	//Assumes starting position is 0
	if (Override){
		Finished = true;
		std::cout << "Override Pressed - Auto Move Abort\n";

	} else if ((LeftPosition > DesiredDistance + DistanceThreshold) || (RightPosition > DesiredDistance + DistanceThreshold)){ //Retract
		Left = 1;
		Right = 1;

		if (error > 0){
			Right = K * Right;
			std::cout << "Adjusting Right Retracting\n";
		} else if (error < 0 ){
			Left = K * Left;
			std::cout << "Adjusting Left Retracting\n";
		}

		std::cout << "Retracting Scimitar\n";
//		scimitar -> Control(Left * ScimitarPrecision, Right * ScimitarPrecision, false);  //KJM Removed this to only send to control function once at bottom.  Values set by if/thens
		Finished = false;
	} else if ((LeftPosition < DesiredDistance - DistanceThreshold) || (RightPosition < DesiredDistance - DistanceThreshold)){ //Extend
		Left = -1;
		Right = -1;

		if (error > 0){
			Left = K * Left;
			std::cout << "Adjusting Left Extending\n";
		} else if (error < 0 ){
			Right = K * Right;
			std::cout << "Adjusting Right Extending\n";
		}

		std::cout << "Extending Scimitar\n";
//		scimitar -> Control(Left * ScimitarPrecision, Right * ScimitarPrecision, false);
		Finished = false;
	} else {
		Finished = true;
		std::cout << "Done running Scimitar\n";
	}
	scimitar -> Control(Left * ScimitarPrecision, Right * ScimitarPrecision, false);

}

// Make this return true when this Command no longer needs to run execute()
bool ScimitarMoveToPosition::IsFinished()
{
	if (scimitar -> ReportAnySwitches()){ //checks limit switches
		std::cout << "ScimitarMoveToPositon Stopped due to limit switch\n";
		Finished = true; //KJM changed this to set the flag rather than execute the return
	}
	std::cout << "ScimitarMoveToPosition Return Checked\n";
	return Finished;
}

// Called once after isFinished returns true
void ScimitarMoveToPosition::End()
{
	scimitar -> Stop();
	std::cout << "ScimitarMoveToPosition Command Ended\n";
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ScimitarMoveToPosition::Interrupted()
{
	scimitar -> Stop();
	std::cout << "Interrupted Scim\n";
}
