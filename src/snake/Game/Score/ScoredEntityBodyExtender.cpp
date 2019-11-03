#include <snake/Game/Score/ScoredEntityBodyExtender.hpp>

namespace snake::game {

    ScoredEntityBodyExtender::ScoredEntityBodyExtender(eventer::EventManager* eventManager, core::World* world)
    : componentsManager(&world->getComponentsManager()) {
        eventManager->subscribe<ScoreEvent>(this);    
    }

    void ScoredEntityBodyExtender::receive(ScoreEvent const& event) {
        if (auto& entity = event.entity; entity->has<physic::ExtendedBodyComponent>()) {
            auto extend = componentsManager->pull<physic::ExtendedBodyComponent>(entity);
            auto body = componentsManager->pull<physic::Body>(entity);
            for (int i = 0; i < extend->segmentsNumber; ++i) {
                body->cloneTail();
            } 
        }
    }


}
