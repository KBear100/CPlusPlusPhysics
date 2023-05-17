#include "Joint.h"
#include "Body.h"
#include "Graphics.h"

Joint::Joint(Body* bodyA, Body* bodyB, float stiffness, float restLenght) :
	m_bodyA{ bodyA },
	m_bodyB{ bodyB },
	m_stiffness{ stiffness },
	m_restLength{ restLenght }
{
	if (m_restLength == 0) m_restLength = glm::distance(bodyA->position, bodyB->position);
}

void Joint::Step(float dt)
{
	glm::vec2 direction = m_bodyA->position - m_bodyB->position;
	float length = glm::length(direction);

	float x = length - m_restLength;
	float f = -m_stiffness * x;

	glm::vec2 ndirection = glm::normalize(direction);
	m_bodyA->ApplyForce(ndirection * f);
	m_bodyB->ApplyForce(-ndirection * f);
	//f = -k * x
}

void Joint::Draw(Graphics* graphics)
{
	graphics->DrawLine(m_bodyA->position, m_bodyB->position, { 1, 1, 1, 1 });
}
