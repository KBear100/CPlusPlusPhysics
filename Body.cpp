#include "Body.h"
#include "Shape.h"
#include "Integrator.h"
#include "World.h"
#include "CircleShape.h"

void Body::ApplyForce(const glm::vec2& force)
{
	this->force += force;
}

void Body::Step(float dt)
{
	if (type != DYNAMIC) return;

	//gravity
	ApplyForce(World::gravity * gravityScale * mass);

	Integrator::SemiImplicitEuler(*this, dt);
	ClearForce();

	// damping
	velocity *= (1.0f / (1.0f + (damping * dt)));
}

void Body::Draw(class Graphics* graphics)
{
	shape->Draw(graphics, position);
}

bool Body::Intersects(Body* body)
{
	glm::vec2 direction = body->position - this->position;
	float distance = glm::length(direction);
	float radius = static_cast<CircleShape*>(this->shape)->radius + static_cast<CircleShape*>(body->shape)->radius;

	return distance <= radius;
}
