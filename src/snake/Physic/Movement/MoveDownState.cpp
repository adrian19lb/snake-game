#include <snake/Physic/Movement/MoveDownState.hpp>
#include <snake/Physic/Movement/VerticalDirectionDetector.hpp>
#include <snake/Physic/Movement/DirectionResponser.hpp>
#include <snake/Physic/Movement/MoveCommand.hpp>

namespace snake::physic {
        
    MoveDownState::MoveDownState(MoveAction lastAction)
    : MoveState(std::make_unique<VerticalDirectionDetector>(lastAction), lastAction) {
        
    }
     
    MoveAction MoveDownState::getActionID() const {
        return MoveAction::MoveDown;
    }

}
