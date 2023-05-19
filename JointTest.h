#pragma once
#include "Test.h"

#define SPRING_STIFFNESS	200
#define SPRING_LENGTH		100
#define BODY_DAMPING		10
#define CHAIN_SIZE			3

class JointTest : public Test
{
public:
	void Initialize() override;

	void Update() override;
	virtual void FixedUpdate() override;
	virtual void Render() override;

private:
	class Body* m_anchor{ nullptr };
};