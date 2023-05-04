#include "ParticleTest.h"

void ParticleTest::Initialize()
{
	Test::Initialize();
}

void ParticleTest::Run()
{
	UpdateEvents();

	m_input->Update();
	m_time->Update();

	m_graphics->SetColor({ 1, 1, 1, 1 });
	m_graphics->Clear();

	m_graphics->DrawCircle(m_input->GetMousePosition(), 30, { randomf(), randomf(), randomf(), 1 });

	m_graphics->Present();
}
