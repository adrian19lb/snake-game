#ifndef BODYEXTENDERRECEIVER_H
#define BODYEXTENDERRECEIVER_H

#include <snake/Eventer/Receiver.hpp>
#include <snake/Eventer/EventManager.hpp>
#include <snake/Core/EntityComponentSystem/World.hpp>
#include <snake/Physic/Body.hpp>
#include <snake/Game/Score/ScoreEvent.hpp>
#include <snake/Physic/BodyExtender/ExtendedBodyComponent.hpp>

namespace snake::game {

    class ScoredEntityBodyExtender : public eventer::Receiver<ScoreEvent> {
    public:
        ScoredEntityBodyExtender(eventer::EventManager* eventManager, core::World* world);

        void receive(ScoreEvent const& event) override;
    private:
        core::ComponentsManager* componentsManager;
    };

}

#endif /* BODYEXTENDERRECEIVER_H */
