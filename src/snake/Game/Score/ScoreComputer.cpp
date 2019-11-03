#include <snake/Game/Score/ScoreComputer.hpp>

namespace snake::game {
        
    ScoreComputer::ScoreComputer(eventer::EventManager* eventManager, core::World* world)
    : componentsManager(&world->getComponentsManager()) {
        eventManager->subscribe<ScoreEvent>(this);
    }
        
    void ScoreComputer::receive(ScoreEvent const& scoreEvent) {
        if (auto& entity = scoreEvent.entity; entity->has<OverallScoreComponent>()) {
            auto overallScoreComponent = componentsManager->pull<OverallScoreComponent>(entity);
            overallScoreComponent->value += scoreEvent.score;
        }
    } 

}
