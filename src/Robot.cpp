/*
 * Main Robot Code for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 *
 *

                                                               .++#'`
                                                          ;#'+#;;';;;# `.`
                                                     ++''+;;''''''''';';;;+.
                                                   ,''';;';'';'''''';;;;;;;;,
                                                   ''';''';';'';;;;;'''';';;'+:
                                                  @''''';;;;;;;;;;;;;;;;'';;;;;#`
                                                .++''''';;;;;;;;;;;;;;;;''';'';;+
                                               +''+''''';';;;;;;;;;;;;;;''''''';;'
                                              :''''''''';;;;;;;;;;;;;;;;'''''';';#
                                              +'''''';'';;;;;;;;;;;;;;;;;;;'''';;;#
                                             `''''''';'';;;;;;;;;;;;;;;;;;;;;'''';;;
                                             .''''''''';;;;;;;;;;;;;;;;;;;;''';'';;#
                                              ''''''';';;;;;;;;;;;;;;;;;;;;'';''';;#
                                            @''''''''''';';;;;;;;;;;;;;;;;;;';'';;;;.
                                           #''''''''';;';;;;;;;;;;;;;;;;;;;';;;''';;#
                                          :''''''''''';';';;;;;;;;;;;;;;;;;';;';''';#
                                          @'''''''''''';''';;;'''';';';'';;;;';;'';;#
                                          #''''''''''''';;';';'';;;''';'''';';';;';;:
                                          @''''''''''''''''';;;'''''''''';'''''';';;
                                          ,''''''''''''''';''';'';'';''';'';+''';';;#
                                           #''''''''''''''''''''';''#+#;:'+:+;'';;';+
                                          #''''''''''''''''''''+#',:::,,,,,,`;;';;;;#
                                          @''''''''''''''';;;,::::,,,,,,,,,,`#'''';;+
                                          @'''''''''''''''+::::,,,,,,,,,,,,,.,'';';@
                                           ''''''''''''''':::::,,,,,,,,,,,,,:,,;;;'
                                          .''''''''''''''#::::,,':.,,,,,,##;;;@;';#
                                          .'''''''''''''';::,'+;;;+,,,,,##;;,;;+;'`
                                           ''''''''''''''#:,#+;;`;;+.,;;++;,;.;#@
                                           +'''''''''''''#:+';;.;,:;',,.`+;;,;;#
                                            @'''''''''''',,#';:;`;;;:,,,,.;;';;`
                                             ,'''''''''''#,#'+;,;;;',,,,,,.#+#+
                                             .'''''''''''+#,''';;;':,,,,,,,.,,:
                                             `'''''''''''+,:,#+#@+,,,,,,,,,.:,:
                                              @'+''''''':,,:::,,,,,,,::,,.,#,,.
                                               +'''''''#'#,,::,,,,:,,:;'':,,,,.:;
                                                `#'''''+:;:,::,,,+,,,,,,,,,,,,,,.#
                                                 #'''''+,:::::,,+,,,,,,,,,,,,,,,,.`
                                                 :'''''''##::,#,,,,,,,,,,,,,,,,,,#
                                                  #'''''''+::+.'':,,,,,,,,,,,:++`
                                                   +''''''#::.+ +``:@#####+':,;#,                 ;:
                                   ';,           `'+;:::::',:.. +   :  + '::::,,,;#:             #,`,
                                   ;,+         :+,:::::::::,:,# ;   `  .:::::::,,,,,@           .,,``
                                   ;,,:       +,,,,:::::::::::,''` .  : #;::::,,,,,+`          .:,,#
                                   #,,,,       ';,,,,::::::;:::,,,:'++:,,;:::,,,,,#           ,:,,.:
                            ``.``` .,,,:,        +:,,,:::::':::,,,,,,,,,+::::,,,,#           .:,,,+;,..`..,;+;
                        `#+:,,,,,,,:#,,,:`        `#,,,::::'::,,,,,,,,,,;:::,,,,+            ',,,,,,,,,,,,,,.`+
                        #,,,,,,,,,,,,,,,,'          ,',,:::'::,,,,,,,,,,;::,,,,+            +,,,,,,,,,,,,,,,,,+
                        #,,,,,,:,,,,,,,,,,'           #,,::'::,,,,,,,,,,;::,,,+             ;,,,,,++#+,#+####:
                         `,..`.:,'+++,,,,,'           ##,,:#::,,,,,,,,,,;:,,,#,;++::#`     `:,,,,,......`
                              :,,,,,,,,,,,,.      ;+,.``#,,;,::,,,,,,,,,#:,,+  ;     '     `,,,,,.;,,,,.`
                              `;::,,'',,,,,'#.   +```+```:,,'::,,,,,,,,,+',:`   +     +    ;,,,,:'##+'+#
                               ':++'',+.,,,#++  +``` .```+,,#::,,,,,,,,,#:,+     #     # #;#,,'+,,,,,,.@
                               ;:,,,,;,,,,,'@: .````;`````:,;,:,,,,,,,,,.',:     +      # ,,,,,,,,'.,,,#
                               +:,,,+,,:,,,,., '````:,````#,,,:,,,+,,+,,.+,:   +,  .'   # @,,,,,,,,;;,#
                                #,,,:,::,,,# .#```````';``',,;:,,,:,,;,,:++' .::#+,  .  ' ,:,,,,,:##@`
                                 `,##::,,,#   ```` ...,,:+`:,@,,,,+,,+,,####         '  ,  .',,,,,+,.#
                                  `,:,::,#    ;`` `     ```+,+#,,,,,:,,,#;##         # ``    #,,,,,,,,#
                                  :,,;:;'     @`  ``     ``#,:#;,,,,;,,,+.#;         # `      `#++....,#
                                 +,,,##`      #  ``;      `:,,;+,,,,;,,+#,+:`        # :          :;:,`:
                                +,.,#.``      ,  ``+       `:,#;+,,,:,,#:,',.        # #          +.``'
                                ++;`````       .  `.        +,:.++,,,,;#,,;,'        + #         ,,.``,
                                #,,'`````      #` ``'       #,,',;+:,,#;,,:,#        : ,        +...`#
                                 ',,+,```      ;; ``'       ;,,#,,:+++#,,::,+        ``       +:...`.
                                 `,,,,:'`        . ``,      `,,:,,:;..'.,',,;       ` ;     ,;.....`'
                                  ',,,,,#`         ``+       ;,,+,+:::.+,#,,:       ;       ;.....`'
                                   +,,,,,:          ```      +,,',+::;::.#,,:.      +       :.:....`
 */

#include "WPILib.h"
#include "Commands/Command.h"
#include "Target.h"
#include "CommandBase.h"
#include "Autonomous/AutonomousLowBar.h"
#include "Autonomous/AutonomousPortcullis.h"
#include "Autonomous/AutonomousChevalDeFrise.h"
#include "Autonomous/AutonomousRamparts.h"
#include "Autonomous/AutonomousMoat.h"
#include "Autonomous/AutonomousDrawbridge.h"
#include "Autonomous/AutonomousSallyPort.h"
#include "Autonomous/AutonomousRockWall.h"
#include "Autonomous/AutonomousRoughTerrain.h"
#include "Autonomous/AutoHookScimitarOnBumper.h"

#include "Autonomous/MoveForwardOnly.h"
#include "Commands/DoNothing.h"

//2016 Stronghold code
class Robot: public IterativeRobot
{
private:
	/*XXX***********
	 * Camera Info
	 ************/

	IMAQdxSession RunningSession;
	Image *frame;
	IMAQdxError imaqError;
//	USBCamera *targetCam;
//	CameraServer *server;
//	int set_bright 	= 1;
//	int set_exp		= 1;
	/************
	 * End Camera info
	 ************/

	/************XXX
	 * Autonomous mode variables
	 ************/
	Command *autonomousCommand;
	LiveWindow *lw;
	SendableChooser *autoMode;
	//Defense positions refer to map of arena in game manual
	int PositionForDefense 	= 0;
	//Position for Goal. 1 for left. 2 for middle. 3 for right. Note that 2 will not be used for low goal because there is no middle low goal
	int PositionForGoal 	= 0;
	//1 is for low goal. 2 is for high goal
	int LowOrHighGoal		= 0;
	/************
	 * End Autonomous mode variables
	 ************/

	void RobotInit()
	{
		CommandBase::init();
//		autonomousCommand = new ExampleCommand();
		lw = LiveWindow::GetInstance();
		SmartDashboard::PutNumber("Position of the Defense", 	PositionForDefense);
		SmartDashboard::PutNumber("Position of the Goal", 		PositionForGoal);
		SmartDashboard::PutNumber("Choose High or Low Goal", 	LowOrHighGoal);
		SmartDashboard::GetNumber("Position of the Defense", 	PositionForDefense);
		SmartDashboard::GetNumber("Position of the High Goal", 	PositionForGoal);
		SmartDashboard::GetNumber("Choose High or Low Goal", 	LowOrHighGoal);

		autoMode = new SendableChooser();
		//Low Bar CommandGroup is constant because it'll always be in defense position 1 and go in left high goal
//		autoMode->AddDefault("Default-Low Bar", new AutonomousLowBar(1,1,2));
		autoMode->AddDefault("ONLY Hook Scimitar onto Bumper", new AutoHookScimitarOnBumper());
		autoMode->AddObject("Low Bar (Hook Forwards)", new AutonomousLowBar(1,1,2));
		autoMode->AddObject("Do Nothing", new DoNothing());
//		autoMode->AddObject("Portcullis", new AutonomousPortcullis(PositionForDefense, PositionForGoal, LowOrHighGoal));
		autoMode->AddObject("Cheval de Frise (SPT Forwards)", new AutonomousChevalDeFrise(PositionForDefense, PositionForGoal, LowOrHighGoal));
//		autoMode->AddObject("Ramparts", new AutonomousRamparts(PositionForDefense, PositionForGoal, LowOrHighGoal));
//		autoMode->AddObject("Moat", new AutonomousMoat(PositionForDefense, PositionForGoal, LowOrHighGoal));
//		autoMode->AddObject("Drawbridge", new AutonomousDrawbridge(PositionForDefense, PositionForGoal, LowOrHighGoal));
//		autoMode->AddObject("Sally Port", new AutonomousSallyPort(PositionForDefense, PositionForGoal, LowOrHighGoal));
		autoMode->AddObject("Rock Wall/Rough Terrain (Hook Forwards)", new AutonomousRockWall(PositionForDefense, PositionForGoal, LowOrHighGoal));
//		autoMode->AddObject("Rough Terrain", new AutonomousRoughTerrain(PositionForDefense, PositionForGoal, LowOrHighGoal));
//		autoMode->AddObject("SpyBot", new AutonomousSpyBot()); //Restore when command is written, plus need one for each position
		autoMode->AddObject("Move Forward to Outer Works Only (SPT Forwards)", new MoveForwardOnly());
//		autoMode->AddObject("Hook Scimitar On Bumper", new AutoHookScimitarOnBumper());
		SmartDashboard::PutData("Autonomous Mode", autoMode);


//		targetCam = new USBCamera("cam0", true);
//		targetCam->SetBrightness(set_bright);
//		targetCam->SetExposureManual(set_exp);
//		targetCam->UpdateSettings();
//		targetCam->CloseCamera();

//Camera Option 1 code start ========= This will display the camera and draw a shape on it - hopefully to show our targeting area
/*	    // create an image
		frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
		//the camera name (ex "cam0") can be found through the roborio web interface
		imaqError = IMAQdxOpenCamera("cam0", IMAQdxCameraControlModeController, &RunningSession);
		if(imaqError != IMAQdxErrorSuccess) {
			DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");
		}
		imaqError = IMAQdxConfigureGrab(RunningSession);
		if(imaqError != IMAQdxErrorSuccess) {
			DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqError) + "\n");
		}*/
//Option 1 code end ==============
/*
//Option 2 code start ============ This will just display the camera, but is much simpler and may not conflict
		CameraServer::GetInstance() -> SetQuality(50);
		CameraServer::GetInstance() -> StartAutomaticCapture("cam0");
//Option 2 code end ===============
 *
 */
	}
	
	void DisabledPeriodic()
	{
/*		SmartDashboard::GetNumber("Position of the Defense", 	PositionForDefense);
		SmartDashboard::GetNumber("Position of the High Goal", 	PositionForGoal);
		SmartDashboard::GetNumber("Choose High or Low Goal", 	LowOrHighGoal);

		autoMode = new SendableChooser();
		//Low Bar CommandGroup is constant because it'll always be in defense position 1 and go in left high goal
		autoMode->AddDefault("Default-Low Bar", new AutonomousLowBar(1,1,2));
		autoMode->AddObject("Portcullis", new AutonomousPortcullis(PositionForDefense, PositionForGoal, LowOrHighGoal));
		autoMode->AddObject("Cheval de Frise", new AutonomousChevalDeFrise(PositionForDefense, PositionForGoal, LowOrHighGoal));
		autoMode->AddObject("Ramparts", new AutonomousRamparts(PositionForDefense, PositionForGoal, LowOrHighGoal));
		autoMode->AddObject("Moat", new AutonomousMoat(PositionForDefense, PositionForGoal, LowOrHighGoal));
//		autoMode->AddObject("Drawbridge", new AutonomousDrawbridge(PositionForDefense, PositionForGoal, LowOrHighGoal));
//		autoMode->AddObject("Sally Port", new AutonomousSallyPort(PositionForDefense, PositionForGoal, LowOrHighGoal));
		autoMode->AddObject("Rock Wall", new AutonomousRockWall(PositionForDefense, PositionForGoal, LowOrHighGoal));
		autoMode->AddObject("Rough Terrain", new AutonomousRoughTerrain(PositionForDefense, PositionForGoal, LowOrHighGoal));
//		autoMode->AddObject("SpyBot", new AutonomousSpyBot()); //Restore when command is written, plus need one for each position
		autoMode->AddObject("Do Nothing", new DoNothing());
		autoMode->AddObject("Move Forward to Outer Works Only", new MoveForwardOnly());
		SmartDashboard::PutData("Autonomous Mode", autoMode);
*/		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		CommandBase::drivebase -> Reset();//Stops DriveBase motors when first enabled
		//CommandBase::spt -> Reset();//Stops the shoulder motor of SPT when first enabled
		autonomousCommand = (Command *) autoMode->GetSelected(); //Dashboard selection command
		autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		CommandBase::drivebase -> Stop();//Stops DriveBase motors when teleop is first enabled
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
	}

	void TeleopPeriodic()
	{

		Scheduler::GetInstance()->Run();
        // grab an image, draw the circle, and provide it for the camera server which will
        // in turn send it to the dashboard.
/*		while(IsOperatorControl() && IsEnabled()) {
			IMAQdxGrab(RunningSession, frame, true, NULL);
			if(imaqError != IMAQdxErrorSuccess) {
				DriverStation::ReportError("IMAQdxGrab error: " + std::to_string((long)imaqError) + "\n");
			} else {
				imaqDrawShapeOnImage(frame, frame, { TargetY, TargetX, TargetHeight, TargetWidth }, DrawMode::IMAQ_DRAW_VALUE, ShapeMode::IMAQ_SHAPE_OVAL, 0.0f);
				CameraServer::GetInstance()->SetImage(frame);
			}
		}
*/	}

	void TestPeriodic()
	{
		lw->Run();
		//I'd like to add a command to run the off board compressor here
	}
};

START_ROBOT_CLASS(Robot);

