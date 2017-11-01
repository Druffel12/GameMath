#pragma once
#include "vec2.h"
#include "Transform2.h"


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
		angularAcceleration,
		torque;
	float angulardrag;
	
		// the sum of all forces appplied ro an object

		// A = F/M
		// F = MA

	Rigidbody() : velocity{ 0,0 },
					accelration{ 0,0 },
					force{ 0,0 },
				  impulse { 0,0 },
				  mass(10),
				  drag(1),
				  angularVelocity(0),
				  angularAcceleration(0),
				  torque(0),
				angulardrag(.25f)
	{

	}


	void integrate(Transform2 &T, float dt)
	{
		accelration = force / mass;
		velocity += accelration * dt + impulse / mass;
		T.position += velocity * dt;
		impulse = { 0,0 };
		force = -velocity * drag;
		// angular mothion (sort of)
		angularAcceleration = torque / mass;
		angularVelocity += angularAcceleration * dt;
		T.angle += angularVelocity * dt;
		torque = angularVelocity * angulardrag;
	}
};