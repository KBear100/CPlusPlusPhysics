#pragma once
#include "Body.h"
#include "Shape.h"

class PhysicsObject
{
public:
	Body* GetBody() { return m_body; }
	Shape* GetShape() { return m_shape; }

protected:
	Body* m_body{ nullptr };
	Shape* m_shape{ nullptr };
};