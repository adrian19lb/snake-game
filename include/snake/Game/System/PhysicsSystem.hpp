#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include <SFML/System/Vector2.hpp>
#include <snake/Eventer/EventManager.hpp>
#include <snake/Game/System/System.hpp>

namespace snake::game {

    class PhysicsSystem : public System {
    public:
        PhysicsSystem(float dt, core::World* world, eventer::EventManager* eventManager);

        void setPosition(const core::Entity* entity, sf::Vector2f position);
    private:
        core::ComponentsManager* componentsManager;
        eventer::EventManager* eventManager;
    };
}

#endif /* PHYSICSSYSTEM_H */
