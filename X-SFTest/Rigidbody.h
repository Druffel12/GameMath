#pragma once
#include "vec2.h"
#include "Transform.h"


class Rigidbody
{
public:
	float mass;


	vec2 velocity, // speed * direction
	accelration, // A = F/M
	force,
	impulse; // continous forces

	float drag,
		angularVelocity,
		torque;
	float angulardrag;
	
		// the sum of all forces appplied ro an object

		// A = F/M
		// F = MA

	Rigidbody() : velocity{ 0,0 },
				  acceleration{ 0,0 },
				  Force { 0,0 },
				  impulse { 0,0 },
				  mass(10),
				  drag(1)
				  angularVelocity(0),
				  angularAcceleration(0),
				  torque(0),
				  angualrDrag(.25f)
	{

	}


	void integrate(Transform &T, float dt)
	{
		acceleration = force / mass;
		velocity += accleration * dt + impulse / mass;
		T.position += velocity * dt;
		impulse = { 0,0 };
		force = -velocity * drag;
		// angular mothion (sort of)
		angularAcceleration = torque / mass;
		andularVelocity += angularAcceleration * dt;
		T.angle += angularVelocity * dt;
		torque = angularVelocity * angularDrag;
	}
};