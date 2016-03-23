 #include "AutoDriveCommand.h"

 //const float	kP_Right = .9;			//Uncomment for getting value from dashboard
 //const float	kP_Left = .835;
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
//	kP_Right = .9;
//	kP_Left = .835;
	kP_Drift = .1;
}

// Called just before this Command runs the first time
void AutoDriveCommand::Initialize()
{
	drivebase -> EncoderReset();
	heading = drivebase -> ReportGyro();
	drift = 0;

	SmartDashboard::PutNumber("heading", heading);
//	SmartDashboard::PutNumber("kP_Left(Forwards)", kP_Left);
//	SmartDashboard::PutNumber("kP_Right(Forwards)", kP_Right);
	SmartDashboard::PutNumber("DRIFT KP", kP_Drift);
	Wait(3);
	SmartDashboard::GetNumber("DRIFT KP", kP_Drift);
//	SmartDashboard::GetNumber("kP_Left(Forwards)", kP_Left);
//	SmartDashboard::GetNumber("kP_Right(Forwards)", kP_Right);
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
//				if (drift > 1) { //drifting to the right
//					drivebase -> Drive(AutoDriveSpeed - (kP_Drift * drift), AutoDriveSpeed);
//				} else if (drift < -3) { //drift left
//					drivebase -> Drive(AutoDriveSpeed, AutoDriveSpeed);
				if (drift < -1){
					drivebase -> Drive(AutoDriveSpeed, AutoDriveSpeed + (kP_Drift * drift));
				} else {
					drivebase -> Drive(AutoDriveSpeed, AutoDriveSpeed);
				}
				DoneTraveling = false;
			} else if (DesiredDistance < 0 && (DistanceTraveled > AutoDistThresh - fabs(DesiredDistance))){ //DesiredDistance is negative, go backward
				if(drift > 1){ //need to find slightly different KP for backwards
					drivebase -> Drive(-(AutoDriveSpeed + (kP_Drift * drift)), -AutoDriveSpeed);//There is no kp value here because the kp value makes the robot run curved when going backwards
				}else{
					drivebase -> Drive(-AutoDriveSpeed, -AutoDriveSpeed);
				}
				DoneTraveling = false;
			} else { //error or exactly 0
				std::cout << "AutoDriveDistance Error!!!\n";
				DoneTraveling = true;
			}
		DistanceTraveled = (drivebase -> GetEncoderDistance());
	}

	//gyro drive straight
/*	float left, right;
	drift = drivebase -> ReportGyro() - heading;
	if (drift > .5) { //drifting to the right
		left  = AutoDriveSpeed - (kP_Left * drift);
		right = AutoDriveSpeed;
	} else if (drift < -.5) { //drifting to the left
		left  = AutoDriveSpeed;
		right = AutoDriveSpeed - (kP_Right * drift);
	}
	drivebase -> Drive(left, right); */
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
