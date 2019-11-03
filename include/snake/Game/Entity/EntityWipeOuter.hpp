#ifndef ENTITYWIPEOUTER_H
#define ENTITYWIPEOUTER_H

#include <snake/Eventer/Receiver.hpp>
#include <snake/Eventer/EventManager.hpp>
#include <snake/Core/EntityComponentSystem/World.hpp>
#include <snake/Game/Score/ScoreEvent.hpp>

namespace snake::game {
    
    class EntityWipeOuter : public eventer::Receiver<ScoreEvent> {
    public:
        EntityWipeOuter(eventer::EventManager* eventManager, core::World* world)
        : world(world) {
            eventManager->subscribe<ScoreEvent>(this);
        }

        void receive(ScoreEvent const& event) {
            world->erase(event.scorableEntity);
        }
    private:
        core::World* world;
    };


}

#endif /* ENTITYWIPEOUTER_H */
