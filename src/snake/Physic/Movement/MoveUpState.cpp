#include <snake/Physic/Movement/MoveUpState.hpp>
#include <snake/Physic/Movement/VerticalDirectionDetector.hpp>
#include <snake/Physic/Movement/DirectionResponser.hpp>
#include <snake/Physic/Movement/MoveUpCommand.hpp>

namespace snake::physic {
        
    MoveUpState::MoveUpState(MoveAction lastAction) 
    : MoveState(std::make_unique<VerticalDirectionDetector>(lastAction), lastAction) {
        
    }

    MoveAction MoveUpState::getActionID() const {
        return MoveAction::MoveUp;
    }

}
