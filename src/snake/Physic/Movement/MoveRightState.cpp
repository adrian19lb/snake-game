#include <snake/Physic/Movement/MoveRightState.hpp>
#include <snake/Physic/Movement/DirectionResponser.hpp>
#include <snake/Physic/Movement/HorizontalDirectionDetector.hpp>

namespace snake::physic {
        
    MoveRightState::MoveRightState(MoveAction lastAction)
    : MoveState(std::make_unique<HorizontalDirectionDetector>(lastAction), lastAction) {
        
    }
    
    MoveAction MoveRightState::getActionID() const {
        return MoveAction::MoveRight;
    }

}
