#include <snake/Physic/Movement/NullMoveState.hpp>
#include <snake/Physic/Movement/UnknowDirectionDetector.hpp>
#include <snake/Physic/Movement/NullMoveCommand.hpp>

namespace snake::physic {

    NullMoveState::NullMoveState(MoveAction lastAction)
    : MoveState(std::make_unique<UnknownDirectionDetector>(lastAction), lastAction) {
        
    }
       
    MoveAction NullMoveState::getActionID() const {
        return MoveAction::Unknow;
    }

}
