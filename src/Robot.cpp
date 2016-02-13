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

//2016 Stronghold code
class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	LiveWindow *lw;
	SendableChooser *autoMode;
	//Displays variables necessary for autonomous mode
	//Defense positions refer to map of arena in game manual
	int PositionForDefense 	= 0;
	//Position for Goal. 1 for left. 2 for middle. 3 for right. Note that 2 will not be used for low goal because there is no middle low goal
	int PositionForGoal 	= 0;
	//1 is for low goal. 2 is for high goal
	int LowOrHighGoal		= 0;

	void RobotInit()
	{
		CommandBase::init();
//		autonomousCommand = new ExampleCommand();
		lw = LiveWindow::GetInstance();

		SmartDashboard::PutNumber("Position of the Defense", 	PositionForDefense);
		SmartDashboard::PutNumber("Position of the Goal", 		PositionForGoal);
		SmartDashboard::PutNumber("Choose High or Low Goal", 	LowOrHighGoal);

/*			MOVED DOWN TO DISABLED PERIODIC()
 *
 *			autoMode = new SendableChooser();
 *	//		Low Bar CommandGroup is constant because it'll always be in defense position 1 and go in left goal
 *			autoMode->AddDefault("Default-Low Bar", new AutonomousLowBar(1,1));
 *			autoMode->AddObject("Portcullis", new AutonomousPortcullis(PositionForGoal, PositionForDefense));
 *			autoMode->AddObject("Cheval de Frise", new AutonomousChevalDeFrise(PositionForGoal, PositionForDefense));
 *			autoMode->AddObject("Ramparts", new AutonomousRamparts(PositionForGoal, PositionForDefense));
 *			autoMode->AddObject("Moat", new AutonomousMoat(PositionForGoal, PositionForDefense));
 *	//		autoMode->AddObject("Drawbridge", new AutonomousDrawbridge(PositionForGoal, PositionForDefense));
 *	//		autoMode->AddObject("Sally Port", new AutonomousSallyPort(PositionForGoal, PositionForDefense));
 *			autoMode->AddObject("Rock Wall", new AutonomousRockWall(PositionForGoal, PositionForDefense));
 *			autoMode->AddObject("Rough Terrain", new AutonomousRoughTerrain(PositionForGoal, PositionForDefense));
 *	//		autoMode->AddObject("SpyBot", new AutonomousSpyBot()); //Restore when command is written, plus need one for each position
 *			SmartDashboard::PutData("Autonomous Mode", autoMode);
 */


//		CameraServer::GetInstance() -> SetQuality(50);
//		CameraServer::GetInstance() -> StartAutomaticCapture("cam0");
	}
	
	void DisabledPeriodic()
	{
		SmartDashboard::GetNumber("Position of the High Goal", PositionForGoal);
		SmartDashboard::GetNumber("Position of the Defense", 	PositionForDefense);
		autoMode = new SendableChooser();
		//Low Bar CommandGroup is constant because it'll always be in defense position 1 and go in left goal
		autoMode->AddDefault("Default-Low Bar", new AutonomousLowBar(1,1));
		autoMode->AddObject("Portcullis", new AutonomousPortcullis(PositionForGoal, PositionForDefense));
		autoMode->AddObject("Cheval de Frise", new AutonomousChevalDeFrise(PositionForGoal, PositionForDefense));
		autoMode->AddObject("Ramparts", new AutonomousRamparts(PositionForGoal, PositionForDefense));
		autoMode->AddObject("Moat", new AutonomousMoat(PositionForGoal, PositionForDefense));
//		autoMode->AddObject("Drawbridge", new AutonomousDrawbridge(PositionForGoal, PositionForDefense));
//		autoMode->AddObject("Sally Port", new AutonomousSallyPort(PositionForGoal, PositionForDefense));
		autoMode->AddObject("Rock Wall", new AutonomousRockWall(PositionForGoal, PositionForDefense));
		autoMode->AddObject("Rough Terrain", new AutonomousRoughTerrain(PositionForGoal, PositionForDefense));
//		autoMode->AddObject("SpyBot", new AutonomousSpyBot()); //Restore when command is written, plus need one for each position
		SmartDashboard::PutData("Autonomous Mode", autoMode);
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		autonomousCommand = (Command *) autoMode->GetSelected(); //Dashboard selection command
		autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
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
	}

	void TestPeriodic()
	{
		lw->Run();
		//I'd like to add a command to run the off board compressor here
	}
};

START_ROBOT_CLASS(Robot);

