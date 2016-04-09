 #include "AutoDriveCommand.h"

 const double AutoDriveSpeed	= 0.85; //.4 for inital lowbar
 const float DefaultTurnPrecision = 0.5;
 const float AutoDistThresh = 2;
AutoDriveCommand::AutoDriveCommand(float DistanceInput) //This will compile after you restart robot code 80% sure
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
	Timeout = 0;
}
/*
AutoDriveCommand::AutoDriveCommand(float DistanceInput, double time) //This will compile after you restart robot code 80% sure
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
	Timeout = time;
}
*/
// Called just before this Command runs the first time
void AutoDriveCommand::Initialize()
{
	if (Timeout > 0)
		SetTimeout(Timeout);

	drivebase -> EncoderReset();
	heading = drivebase -> ReportGyro();
	drift = 0;
	DoneTraveling = true;
	DistanceTraveled = 0;

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
					drivebase -> Drive(AutoDriveSpeed, AutoDriveSpeed + (kP_Drift * drift)); //Adjust right motor when driving forward
				} else {
					drivebase -> Drive(AutoDriveSpeed, AutoDriveSpeed);
				}
				DoneTraveling = false;
			//	std::cout << "Auto Driving Forward\n";
			} else if (DesiredDistance < 0 && (DistanceTraveled > AutoDistThresh - fabs(DesiredDistance))){ //DesiredDistance is negative, go backward
				if(drift > .5){ //Currently assumes we always drift right while going backwards
					drivebase -> Drive(-(AutoDriveSpeed + (kP_Drift * drift)), -AutoDriveSpeed);//Adjusts left motor when driving backwards
				}else{
					drivebase -> Drive(-AutoDriveSpeed, -AutoDriveSpeed);
				}
				DoneTraveling = false;
			//	std::cout << "Auto Driving Backward\n";
			} else { //error, exactly 0, or done
				std::cout << "AutoDriveDistance Finished\n";
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
