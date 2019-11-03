#include <snake/Physic/Movement/NullMoveCommand.hpp>

namespace snake::physic {
        

    void NullMoveCommand::execute(MoveBehaviour* moveBehaviour, float dt) {
    
    }

    MoveAction NullMoveCommand::getID() const {
        return MoveAction::Unknow;
    }

}
