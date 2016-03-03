#include "UpAndDownInfeeder.h"

const float SPTDeliveryPosition 	= 55;//-34.677 from start
const float SPTFeederPosition		= -21;//-112.146 from start
float SPTAngleTolerance = 2;

UpAndDownInfeeder::UpAndDownInfeeder()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(spt);
	POVPress = false;
	POV = 0;
}

// Called just before this Command runs the first time
void UpAndDownInfeeder::Initialize()
{
}

// Called repeatedly when this Command is scheduled to run
void UpAndDownInfeeder::Execute()
{
	if (oi->GetPOVState())
		POV = oi -> GetPOVState();

	if (POV)
		POVPress = true;
	else
		POVPress = false;

	bool SPT_Override = (oi	->	GetMOHButtonL3());

	if (SPT_Override)
		POVPress = false; //override automatic SPT movement

	if (POVPress) {	//POV is D-Pad
		if (POV == 1){
			SPTMoveToSetPoint(SPTDeliveryPosition); //SPT to Delivery
		} else if (POV == -1){
			SPTMoveToSetPoint(SPTFeederPosition); //SPT to Infeed
		} else {
			std::cout << "ERROR 1 - UpAndDownInfeeder::Execute\n";
		}
	} else if (!POVPress){
		//Gets the value of up or down
		double UpOrDownValue = oi -> GetUpOrDownValueInfeeder();
		//Tells the Infeeder to go up or down
		spt -> UpAndDown(UpOrDownValue, SPT_Override);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool UpAndDownInfeeder::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void UpAndDownInfeeder::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void UpAndDownInfeeder::Interrupted()
{

}

void UpAndDownInfeeder::SPTMoveToSetPoint(float DesiredAngle) {
	if (spt -> GetAdjustedEncDistance() > DesiredAngle + SPTAngleTolerance){
		spt -> UpAndDown(1, false); //positive value goes down
	} else if (spt ->GetAdjustedEncDistance() < DesiredAngle - SPTAngleTolerance){
		spt -> UpAndDown(-1, false);//negative value goes up
	} else {
		POVPress = false;
		POV = 0;
	}
}
