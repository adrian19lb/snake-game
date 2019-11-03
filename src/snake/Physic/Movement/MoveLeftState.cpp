#include <snake/Physic/Movement/MoveLeftState.hpp>
#include <snake/Physic/Movement/DirectionResponser.hpp>
#include <snake/Physic/Movement/HorizontalDirectionDetector.hpp>

namespace snake::physic {
        
    MoveLeftState::MoveLeftState(MoveAction lastAction)
    : MoveState(std::make_unique<HorizontalDirectionDetector>(lastAction), lastAction) {
        
    }

    MoveAction MoveLeftState::getActionID() const {
        return MoveAction::MoveLeft;
    }

}
