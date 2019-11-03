#include <snake/Core/EntityComponentSystem/World.hpp>
#include <snake/Physic/Rotation/RotationProcessor.hpp>
#include <snake/Physic/Movement/MoveCommandProcessor.hpp>
#include <snake/Physic/Movement/MoveBehaviourProcessor.hpp>
#include <snake/Physic/Collision/CollisionProcessor.hpp>
#include <snake/Game/System/PhysicsSystem.hpp>

namespace snake::game {
    
    PhysicsSystem::PhysicsSystem(float dt, core::World* world, eventer::EventManager* eventManager)
    : System(world)
    , componentsManager(&world->getComponentsManager())
    , eventManager(eventManager) {
        System::add(std::make_unique<physic::MoveCommandProcessor>());
        System::add(std::make_unique<physic::MoveBehaviourProcessor>(dt));
        System::add(std::make_unique<physic::RotationProcessor>());
        System::add(std::make_unique<physic::CollisionProcessor>(eventManager, componentsManager));
        System::registerProcesorsToWorld();
    }

    void PhysicsSystem::setPosition(const core::Entity* entity, sf::Vector2f position) {
        auto body = componentsManager->pull<physic::Body>(entity);
        auto move = body->head().position - position;
        body->head().position = position;
        while (body->head().prev) {
            body->head().prev->position += move; 
        }
    }

}
