#include <snake/Physic/Movement/MoveLeftCommand.hpp>
#include <snake/Physic/Movement/MoveBehaviour.hpp>

namespace snake::physic {
        
    void MoveLeftCommand::execute(MoveBehaviour* moveBehaviour, float dt) {
        moveBehaviour->moveLeft(dt); 
    } 

    MoveAction MoveLeftCommand::getID() const {
        return MoveAction::MoveLeft;
    }

}
