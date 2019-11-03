#ifndef SCORABLEENTITYRANDOMPOSITIONMAKER_H
#define SCORABLEENTITYRANDOMPOSITIONMAKER_H

#include <snake/Eventer/Receiver.hpp>
#include <snake/Eventer/EventManager.hpp>
#include <snake/Core/RandomNumberGenerator.hpp>
#include <snake/Core/EntityComponentSystem/World.hpp>
#include <snake/Physic/Collision/BodyCollisionDetector.hpp>
#include <snake/Game/Score/ScoreEvent.hpp>

namespace snake::game {

    class ScorableEntityRandomPositionMaker : public eventer::Receiver<ScoreEvent> {
    public:
        ScorableEntityRandomPositionMaker(eventer::EventManager* eventManager, core::World* world);

        void receive(ScoreEvent const& event) override;
    private:
        core::World* world; 
        core::RandomGenerator<int> positionGenerator;
    };

}

#endif /* SCORABLEENTITYRANDOMPOSITIONMAKER_H */
