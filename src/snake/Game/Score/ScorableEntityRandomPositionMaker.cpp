#include <snake/Game/Score/ScorableEntityRandomPositionMaker.hpp>

namespace snake::game {
        
    ScorableEntityRandomPositionMaker::ScorableEntityRandomPositionMaker(eventer::EventManager* eventManager, core::World* world)
    : world(world) {
        eventManager->subscribe<ScoreEvent>(this);
    }

    void ScorableEntityRandomPositionMaker::receive(ScoreEvent const& event) {
        auto entityBody = world->getComponentsManager().pull<physic::Body>(event.entity);
        auto scorableEntityBody = world->getComponentsManager().pull<physic::Body>(event.scorableEntity);
        physic::BodyCollisionDetector collisionResponser(entityBody);
        do {
            auto dy = positionGenerator(1, world->getSize().x);
            auto dx = positionGenerator(1, world->getSize().y);
            scorableEntityBody->head().position = sf::Vector2f(dx, -dy);
            
        }while(collisionResponser.isAnyPhysicComponentOverlapedIn(scorableEntityBody));
             
    }

}
