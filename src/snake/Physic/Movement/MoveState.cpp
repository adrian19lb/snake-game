#include <snake/Physic/Movement/MoveState.hpp>
#include <snake/Physic/Movement//ChangedDirectionDetector.hpp>
#include <snake/Physic/Movement/MoveCommand.hpp>

namespace snake::physic {
        
    MoveState::MoveState(ChangedDirectionDetectorUPtr directionChangeDetector, MoveAction lastAction)
    : directionChangeDetector(std::move(directionChangeDetector))
    , lastAction(lastAction) {
        
    }

    MoveCommand* MoveState::createMoveCommand() const {
        if (directionChangeDetector->isDirectionChanged()) {
            return mapper.get(getActionID());
        }else {
            return mapper.get(lastAction);
        }
    }

}
