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

	void AddBody(struct Body* body);
	void RemoveBody(struct Body* body);

	void AddForceGenerator(class ForceGenerator* forceGenerator);

public:
	static glm::vec2 gravity;

private:
	std::list<struct Body*> m_bodies;
	std::vector<class ForceGenerator*> m_forceGenerators;
};