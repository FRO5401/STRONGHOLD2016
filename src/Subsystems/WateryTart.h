/*
 * Targeting subsystem header for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 * Come and see the violence inherent in the system. Help! Help! I'm being repressed!
 */

#ifndef SRC_SUBSYSTEMS_WATERYTARTX_H_
#define SRC_SUBSYSTEMS_WATERYTARTX_H_
#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "Libraries/LCameraServer.h"


class WateryTart: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Image* frame;
	Image* SecondFrame;
	Image* binaryFrame;
	Image* TargetFrame;
	IMAQdxSession session;
	int imaqError;
	USBCamera* MainCam;
//	double WaitTime;

public:
	//Declares the parts of the robot necessary for this subsystem

	WateryTart();
	void InitDefaultCommand();
	float Search(Range, Range, Range, float, float, double);
	void Manual();
	void Stop();
	void Reset();
	void SendToDashboard(Image*, int);
	static bool CompareParticleSizes(ParticleReport, ParticleReport);
	double ratioToScore(double);
	double AreaScore(ParticleReport);
	double AspectScore(ParticleReport);
	double computeDistance (Image, ParticleReport);

};

#endif /* SRC_SUBSYSTEMS_TARGETING_H_ */
