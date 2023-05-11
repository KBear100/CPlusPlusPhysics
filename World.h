#pragma once
#include <glm/glm.hpp>
#include <vector>
#include <list>

class World
{
public:
	~World();

	void Step(float dt);
	void Draw(class Graphics* graphics);

	void AddBody(class Body* po);
	void RemoveBody(class Body* po);

	void AddForceGenerator(class ForceGenerator* forceGenerator);

public:
	static glm::vec2 gravity;

private:
	std::list<class Body*> m_bodies;
	std::vector<class ForceGenerator*> m_forceGenerators;
};