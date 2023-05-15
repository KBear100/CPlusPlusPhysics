#include "ForceTest.h"
#include "Body.h"
#include "CircleShape.h"
#include "GravitationalGenerator.h"

void ForceTest::Initialize()
{
	Test::Initialize();

	auto forceGenerator = new GravitationalGenerator(400);
	m_world->AddForceGenerator(forceGenerator);
}

void ForceTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = randomUnitCircle() * randomf(100, 200);

		float size = randomf(1, 8);
		auto body = new Body(new CircleShape(randomf(5, 20), { randomf(), randomf(), randomf(), 1 }), m_input->GetMousePosition(), velocity);
		body->damping = 1;
		body->gravityScale = 0;

		m_world->AddBody(body);
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
