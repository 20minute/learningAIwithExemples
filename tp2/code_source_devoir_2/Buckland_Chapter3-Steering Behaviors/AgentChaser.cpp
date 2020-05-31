#include "AgentChaser.h"
#include "SteeringBehaviors.h"

AgentChaser::AgentChaser(GameWorld * world,
						Vector2D position, double rotation, 
						Vector2D velocity, 
						double mass, 
						double max_force, 
						double max_speed, 
						double max_turn_rate, 
						double scale,
						VehicleType type,
						Vehicle* currentLeader) : Vehicle(world,
												position,
												rotation,
												velocity,
												mass,
												max_force,
												max_speed,
												max_turn_rate,
												scale)
{
	Vehicle::SetVehicleType(type);
	if (Vehicle::Type() == VehicleType::chaser) {
		previousLeader = currentLeader;
		Vehicle::Steering()->OffsetPursuitOn(previousLeader, Vector2D(0, 0.0001));
		Vehicle::Steering()->SeparationOn();
	} 
	
}

AgentChaser::AgentChaser(GameWorld * world,
	Vector2D position, double rotation,
	Vector2D velocity,
	double mass,
	double max_force,
	double max_speed,
	double max_turn_rate,
	double scale,
	VehicleType type,
	Vehicle* currentLeader,
	int chaserNumber) : Vehicle(world,
		position,
		rotation,
		velocity,
		mass,
		max_force,
		max_speed,
		max_turn_rate,
		scale)
{
	Vehicle::SetVehicleType(type);

	if (Vehicle::Type() == VehicleType::chaserHumain) {

		switch (chaserNumber)
		{
		case 0: //EST
			Vehicle::Steering()->OffsetPursuitOn(currentLeader, Vector2D(15, 20));
			break;

		case 1: //NORD
			Vehicle::Steering()->OffsetPursuitOn(currentLeader, Vector2D(40, 0));
			break;

		case 2: //SUD
			Vehicle::Steering()->OffsetPursuitOn(currentLeader, Vector2D(-10, 0));
			break;

		case 3: //OUEST
			Vehicle::Steering()->OffsetPursuitOn(currentLeader, Vector2D(15, -20));
			break;

		default:

			break;
		}

		Vehicle::Steering()->SeparationOn();
	}

}

AgentChaser::~AgentChaser()
{
	//delete Vehicle::Steering();
	//delete Vehicle::HeadingSmoother();
}

void AgentChaser::Update(double time_elapsed)
{
	Vehicle::Update(time_elapsed);
}