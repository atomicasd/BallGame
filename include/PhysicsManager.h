#pragma once

class b2World;
class b2Body;
class b2BodyDef;
class PhysicsManager
{
private:
	static PhysicsManager* physicsManagerInstance;
	b2World* box2d_world;

	int	velocityIterations;
	int	positionIterations;
	float timeStep;

public:
	static PhysicsManager* Instance();
	PhysicsManager();
	~PhysicsManager();

	void Step();

	b2Body* CreateBody( b2BodyDef* bodyDef );
	void DestroyBody( b2Body* body );
};