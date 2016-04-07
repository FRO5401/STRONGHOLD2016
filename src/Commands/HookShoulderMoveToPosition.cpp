#include "HookShoulderMoveToPosition.h"
//This code is pretty much a copy of SPTMoveToPositon for the HookShoulder
const double HookShoulderAngleTolerance = 5;//TODO adjust this
const double HookShoulderPrecision = .37;

HookShoulderMoveToPosition::HookShoulderMoveToPosition(double angleForHookShoulder)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(hookshoulder);
	finishedHookShoulder = true;
	DesiredAngleHookShoulder = angleForHookShoulder;
	Timeout = 0;
}

HookShoulderMoveToPosition::HookShoulderMoveToPosition(double angleForHookShoulder, double time)
{
	// Use Requires() here to declare subsystem dependencies
	Requires(hookshoulder);
	finishedHookShoulder = true;
	DesiredAngleHookShoulder = angleForHookShoulder;
	Timeout = time;
}

// Called just before this Command runs the first time
void HookShoulderMoveToPosition::Initialize()
{
	if (Timeout > 0)
		SetTimeout(Timeout);
}

// Called repeatedly when this Command is scheduled to run
void HookShoulderMoveToPosition::Execute()
{
	if (hookshoulder -> ReportAngle() > DesiredAngleHookShoulder + HookShoulderAngleTolerance){
		hookshoulder -> UpAndDown(1.0 * HookShoulderPrecision, false);//Position goes down because desired angle is underneath the current angle, positive goes down
		finishedHookShoulder = false;
		std::cout << "Auto Moving HookShoulder Down\n";
	} else if (hookshoulder ->ReportAngle() < DesiredAngleHookShoulder - HookShoulderAngleTolerance){
		hookshoulder -> UpAndDown(-1.0 * HookShoulderPrecision, false); //Position goes up because desired angle is above current angle, negative goes up
		finishedHookShoulder = false;
		std::cout << "Auto Moving HookShoulder Up\n";
	} else {
		std::cout << "STOP AutoHookShoulder\n";
		finishedHookShoulder = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool HookShoulderMoveToPosition::IsFinished()
{
	return finishedHookShoulder;
}

// Called once after isFinished returns true
void HookShoulderMoveToPosition::End()
{
	hookshoulder -> StopHookShoulder();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HookShoulderMoveToPosition::Interrupted()
{
	hookshoulder -> StopHookShoulder();
}
