#ifndef COLLISIONRESPONSERCOMPOSITE_H
#define COLLISIONRESPONSERCOMPOSITE_H

#include <vector>
#include <snake/Eventer/EventManager.hpp>
#include <snake/Core/EntityComponentSystem/World.hpp>

namespace snake::game {
    
    class CollisionResponserComposite {
    public:
        CollisionResponserComposite(eventer::EventManager* eventManager, core::World* world)
        : eventManager(eventManager)
        , world(world) {
        
        }

        template<typename ResponserType> void create() {
            collisionResponsers.emplace_back(std::make_unique<ResponserType>(eventManager, world)); 
        }
    private:
        eventer::EventManager* eventManager;
        core::World* world; 
        std::vector<std::unique_ptr<eventer::BaseReceiver>> collisionResponsers;
    };

}

#endif /* COLLISIONRESPONSERCOMPOSITE_H */
