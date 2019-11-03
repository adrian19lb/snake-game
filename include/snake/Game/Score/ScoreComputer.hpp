#ifndef SCORECOMPUTER_H
#define SCORECOMPUTER_H

#include <snake/Eventer/Receiver.hpp>
#include <snake/Eventer/EventManager.hpp>
#include <snake/Core/EntityComponentSystem/World.hpp>
#include <snake/Game/Score/ScoreEvent.hpp>
#include <snake/Game/Score/OverallScoreComponent.hpp>

namespace snake::game {
    
    class ScoreComputer : public eventer::Receiver<ScoreEvent> {
    public:
        ScoreComputer(eventer::EventManager* eventManager, core::World* world);
    public:
        void receive(ScoreEvent const& scoreEvent);
    private:
        core::ComponentsManager* componentsManager;
    };


}


#endif /* SCORECOMPUTER_H */
