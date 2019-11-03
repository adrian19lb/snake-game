#ifndef COLLISIONSCORECOMPONENTNOTIFIER_H
#define COLLISIONSCORECOMPONENTNOTIFIER_H

#include <snake/Physic/Collision/SpecificCollisionTypeNotifier.hpp>
#include <snake/Game/Score/ScoreComponent.hpp>
#include <snake/Game/Score/ScoreEvent.hpp>

namespace snake::game {
    
    class CollisionScoreComponentNotifier : public physic::SpecificCollisionTypeNotifier<ScoreComponent> {
    public:
        CollisionScoreComponentNotifier(core::Entity *const entity, eventer::EventManager* eventManager, core::ComponentsManager* componentsManager)
        : SpecificCollisionTypeNotifier(entity, eventManager, componentsManager)
        , mComponentsManager(componentsManager) {
        
        }

    protected:
        std::unique_ptr<physic::BodyCollisionDetector> createBodyCollisionComponent(core::Entity *const entity) override {
            auto body = mComponentsManager->pull<physic::Body>(entity);
            
            return std::make_unique<physic::BodyCollisionDetector>(body); 
        }

        std::unique_ptr<eventer::Event<ScoreComponent>> createEvent(core::Entity *const entity, core::Entity *const scorableEntity) override {
            auto event = std::make_unique<ScoreEvent>(entity, scorableEntity);
            auto scoreComponent = mComponentsManager->pull<ScoreComponent>(scorableEntity);
            event->score = scoreComponent->score;
            
            return event;
       }
    private:
        core::ComponentsManager* mComponentsManager;
    };



}

#endif /* COLLISIONSCORECOMPONENTNOTIFIER_H */
