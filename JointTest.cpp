#include "JointTest.h"
#include "CircleShape.h"
#include "World.h"
#include "Body.h"
#include "Joint.h"

//#define CHAIN

void JointTest::Initialize()
{
	Test::Initialize();

	m_anchor = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 400, 100 }, { 0, 0 }, 0, Body::KINEMATIC);
	m_world->AddBody(m_anchor);

	auto prevBody = m_anchor;

#if defined(CHAIN)
	for (int i = 0; i < CHAIN_SIZE; i++)
	{
		auto body = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 400, 200 }, { 0, 0 }, 1, Body::DYNAMIC);
		body->gravityScale = 250;
		body->damping = 0.75f;
		m_world->AddBody(body);

		auto joint = new Joint(prevBody, body, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint);

		prevBody = body;
	}
#else
	Body* prevA = nullptr;
	Body* prevB = nullptr;

	for (int i = 0; i < CHAIN_SIZE; i++)
	{
		auto bodyA = new Body (new CircleShape(20, { 1, 1, 1, 1 }), { 400, 300 }, { 0, 0 }, 1, Body::DYNAMIC);
		bodyA->gravityScale = 250;
		bodyA->damping = 0.75f;
		auto bodyB = new Body (new CircleShape(20, { 1, 1, 1, 1 }), { 500, 300 }, { 0, 0 }, 1, Body::DYNAMIC);
		bodyB->gravityScale = 250;
		bodyB->damping = 0.75f;

		m_world->AddBody(bodyA);
		m_world->AddBody(bodyB);

		auto joint = new Joint(bodyA, bodyB, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint);

		if (i == 0)
		{
			joint = new Joint(bodyA, m_anchor, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint);
			joint = new Joint(bodyB, m_anchor, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint);
		}
		else
		{
			joint = new Joint(bodyA, prevA, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint);
			
			joint = new Joint(bodyB, prevB, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint);

			joint = new Joint(bodyA, prevB, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint);

			joint = new Joint(bodyB, prevA, SPRING_STIFFNESS, SPRING_LENGTH);
			m_world->AddJoint(joint);
		}

		prevA = bodyA;
		prevB = bodyB;
	}
#endif // CHAIN



	//body = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 400, 200 }, { 0, 0 }, 1, Body::DYNAMIC);
	//body->gravityScale = 250;
	//body->damping = 0.75f;
	//m_world->AddBody(body);

	//joint = new Joint(prevBody, body, SPRING_STIFFNESS, SPRING_LENGTH);
	//m_world->AddJoint(joint);
}

void JointTest::Update()
{
	Test::Update();
	m_anchor->position = m_input->GetMousePosition();
}

void JointTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void JointTest::Render()
{
	m_world->Draw(m_graphics);
	m_graphics->DrawCircle(m_input->GetMousePosition(), 10, { randomf(), randomf(), randomf(), 1 });
}
