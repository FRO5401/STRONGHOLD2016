 #include "AutoDriveCommand.h"

 const double AutoDriveSpeed	= 0.5;
 const float DefaultTurnPrecision = 0.5;
 const float AutoDistThresh = 2;
AutoDriveCommand::AutoDriveCommand(float DistanceInput)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivebase);
	DesiredDistance = DistanceInput;
	DoneTraveling = true;
	DistanceTraveled = 0;
	heading = drivebase -> ReportGyro();
	drift = 0;
	kP_Drift = .1;
}

// Called just before this Command runs the first time
void AutoDriveCommand::Initialize()
{
	drivebase -> EncoderReset();
	heading = drivebase -> ReportGyro();
	drift = 0;

	SmartDashboard::PutNumber("heading", heading);
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveCommand::Execute()
{
	//MainGyro -> Reset();
	if (fabs(DesiredDistance) <= AutoDistThresh){
		std::cout << "DesiredDistance to small!!!\n";
		DoneTraveling = true;
	} else {
		drift = drivebase -> ReportGyro() - heading;
		SmartDashboard::PutNumber("Drift", drift);
			if (DesiredDistance > 0 && (DistanceTraveled < fabs(DesiredDistance) - AutoDistThresh)){ //DesiredDistance is positive, go forward
				if (drift < -.5){ //Currently assumes we always drift left while going forwards
					drivebase -> Drive(AutoDriveSpeed, AutoDriveSpeed + (kP_Drift * drift)); //Adjust right motor when driving forwards
				} else {
					drivebase -> Drive(AutoDriveSpeed, AutoDriveSpeed);
				}
				DoneTraveling = false;
			} else if (DesiredDistance < 0 && (DistanceTraveled > AutoDistThresh - fabs(DesiredDistance))){ //DesiredDistance is negative, go backward
				if(drift > .5){ //Currently assumes we always drift right while going backwards
					drivebase -> Drive(-(AutoDriveSpeed + (kP_Drift * drift)), -AutoDriveSpeed);//Adjusts left motor when driving backwards
				}else{
					drivebase -> Drive(-AutoDriveSpeed, -AutoDriveSpeed);
				}
				DoneTraveling = false;
			} else { //error, exactly 0, or done
				std::cout << "AutoDriveDistance Error!!!\n";
				DoneTraveling = true;
			}
		DistanceTraveled = (drivebase -> GetEncoderDistance());
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveCommand::IsFinished()
{
	return DoneTraveling;
}

// Called once after isFinished returns true
void AutoDriveCommand::End()
{
	drivebase -> Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveCommand::Interrupted()
{
	drivebase -> Stop();
}
