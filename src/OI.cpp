#include "OI.h"
#include "RobotMap.h"

OI::OI()
{
	// Process operator interface input here.
	//AKA physical location of controllers from robot map
	//AKA physical locations of buttons too

	XboxController	= new Joystick(XboxController_Channel);

	//Gives the declared buttons a value that uses the joystick(controller) name and the port number determined
	//by drive station
	JoystickButton * 	Unused;
						XboxA				= new JoystickButton(XboxController, 1);
						XboxB				= new JoystickButton(XboxController, 2);
						XboxX				= new JoystickButton(XboxController, 3);
						XboxY				= new JoystickButton(XboxController, 4);
						UpperLeftTrig		= new JoystickButton(XboxController, 5);
						UpperRightTrig		= new JoystickButton(XboxController, 6);
						XboxBack			= new JoystickButton(XboxController, 7);
						XboxStart			= new JoystickButton(XboxController, 8);
						LeftStickButton		= new JoystickButton(XboxController, 9);
						RightStickButton 	= new JoystickButton(XboxController, 10);
}

//Defines the functions for the axis's declared in the h file
double OI::ReadXboxLeftAxisY()
{
	double LeftForward = XboxController -> GetRawAxis(1);
	return LeftForward;
}

double OI::ReadXboxRightAxisY()
{
	double RightForward = XboxController -> GetRawAxis(5);
	return RightForward;
}
