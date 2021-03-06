#include "PhysicsManager.h"
#include <Box2D\Box2D.h>
#include "CustomContactListener.h"
PhysicsManager* PhysicsManager::physicsManagerInstance;
PhysicsManager* PhysicsManager::Instance()
{
	if( !physicsManagerInstance )
		physicsManagerInstance = new PhysicsManager();
	return physicsManagerInstance;
}
PhysicsManager::PhysicsManager()
{
	velocityIterations = 10;
	positionIterations = 8;
	timeStep = 1.0f / 60.f;

	customContactListener = new CustomContactListener();

	b2Vec2 gravity(0, 9.81f);
	box2d_world = new b2World(gravity);
	box2d_world->SetContactListener( customContactListener );
}

PhysicsManager::~PhysicsManager()
{
	delete customContactListener;
	delete box2d_world;
}

void PhysicsManager::Step()
{
	box2d_world->Step(timeStep,velocityIterations,positionIterations);
}

b2Body* PhysicsManager::CreateBody( b2BodyDef* bodyDef )
{
	return box2d_world->CreateBody( bodyDef );
}

void PhysicsManager::DestroyBody( b2Body* body )
{
	box2d_world->DestroyBody( body );
}

b2World* PhysicsManager::GetWorld()
{
	return box2d_world;
}