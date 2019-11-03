#ifndef SCOREEVENT_H
#define SCOREEVENT_H

#include <snake/Eventer/Event.hpp>
#include <snake/Core/EntityComponentSystem/Entity.hpp>
#include <snake/Game/Score/ScoreComponent.hpp>

namespace snake::game {
    
    struct ScoreEvent : public eventer::Event<ScoreComponent> {
        ScoreEvent(core::Entity *const entity, core::Entity *const scorableEntity)
        : entity(entity)
        , scorableEntity(scorableEntity) {
        
        }

        ScoreEvent(ScoreEvent const& event)
        : entity(event.entity)
        , scorableEntity(event.scorableEntity)
        , score(event.score) {
        
        }

        core::Entity *const entity;
        core::Entity *const scorableEntity;

        int score = 0;
    };

}


#endif /* SCOREEVENT_H */
