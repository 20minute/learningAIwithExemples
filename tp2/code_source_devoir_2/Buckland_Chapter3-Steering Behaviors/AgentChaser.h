#ifndef AgentChaser_H
#define AgentChaser_H

//------------------------------------------------------------------------
//
//  Name:   AgentChaser_H.h
//
//  Desc:   This is an agent chaser, which chases the agent leader
//
//  Author: Lijun Zheng
//
//------------------------------------------------------------------------
#include "Vehicle.h"

class AgentChaser : public Vehicle {
private:
	Vehicle* previousLeader;
public:
	AgentChaser(GameWorld* world,
		Vector2D position,
		double    rotation,
		Vector2D velocity,
		double    mass,
		double    max_force,
		double    max_speed,
		double    max_turn_rate,
		double    scale,
		VehicleType type,
		Vehicle* currentLeader);

	AgentChaser(GameWorld* world,
		Vector2D position,
		double    rotation,
		Vector2D velocity,
		double    mass,
		double    max_force,
		double    max_speed,
		double    max_turn_rate,
		double    scale,
		VehicleType type,
		Vehicle* currentLeader,
		int chaserNumber);

	~AgentChaser();
	void    Update(double time_elapsed);
};

#endif