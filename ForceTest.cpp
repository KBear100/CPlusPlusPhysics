#include "ForceTest.h"
#include "PhysicsObject.h"
#include "CircleShape.h"

void ForceTest::Initialize()
{
	Test::Initialize();

	//World::gravity = { 4, 9.8f };
}

void ForceTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity{ 0, 0 };// = randomUnitCircle() * randomf(100, 200);

		float size = randomf(1, 8);
		auto body = new Body(m_input->GetMousePosition(), velocity, size);
		auto po = new PhysicsObject(body, new CircleShape(size * 2, { randomf(), randomf(), randomf(), 1 }));
		po->GetBody()->damping = 1;
		po->GetBody()->gravityScale = 30;

		m_world->AddPhysicsObject(po);
	}
}

void ForceTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ForceTest::Render()
{
	m_world->Draw(m_graphics);
	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });
}
