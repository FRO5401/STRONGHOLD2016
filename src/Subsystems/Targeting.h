/*
 * Targeting subsystem header for 2016 FRC Stronghold game
 * Team 5401 Fightin' Robotic Owls
 * FROGramming team
 */

#ifndef SRC_SUBSYSTEMS_TARGETING_H_
#define SRC_SUBSYSTEMS_TARGETING_H_
#include "Commands/Subsystem.h"
#include "WPILib.h"

class Targeting: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	//Declares the parts of the robot necessary for this subsystem

	Targeting();
	void Search();
	void Manual();
	void Stop();
	void Reset();
	void SendToDashboard();
	bool CompareParticleSizes(ParticleReport, ParticleReport);
	double ratioToScore(double);
	double AreaScore(ParticleReport);
	double AspectScore(ParticleReport);
	double computeDistance (Image, ParticleReport);
};

#endif /* SRC_SUBSYSTEMS_TARGETING_H_ */
