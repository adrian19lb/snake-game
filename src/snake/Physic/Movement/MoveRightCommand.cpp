#include <snake/Physic/Movement/MoveRightCommand.hpp>
#include <snake/Physic/Movement/MoveBehaviour.hpp>

namespace snake::physic {
        
    void MoveRightCommand::execute(MoveBehaviour* moveBehaviour, float dt) {
        moveBehaviour->moveRight(dt); 
    } 
    
    MoveAction MoveRightCommand::getID() const {
        return MoveAction::MoveRight;
    }

}
