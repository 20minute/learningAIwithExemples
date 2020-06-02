#include "AgentLeader.h"
#include "SteeringBehaviors.h"

AgentLeader::AgentLeader(GameWorld * world, 
						Vector2D position, 
						double rotation, Vector2D velocity, 
						double mass, double max_force, 
						double max_speed, 
						double max_turn_rate, 
						double scale,
						VehicleType type,
						bool manControl) : Vehicle(world,
												position,
												rotation,
												velocity,
												mass,
												max_force,
												max_speed,
												max_turn_rate,
												scale)
{
	m_isManControl = manControl;

	Vehicle::SetVehicleType(type);

	Vehicle::SetScale(Vector2D(10, 10));
	Vehicle::Steering()->WanderOn();
	Vehicle::SetMaxSpeed(70);

}

AgentLeader::~AgentLeader()
{
}

void AgentLeader::Update(double time_elapsed)
{
	Vehicle::Update(time_elapsed);
}
