#include <snake/Physic/Movement/MoveUpCommand.hpp>
#include <snake/Physic/Movement/MoveBehaviour.hpp>

namespace snake::physic {
       
    void MoveUpCommand::execute(MoveBehaviour* moveBehaviour, float dt) {
        moveBehaviour->moveUp(dt); 
    } 
        
    MoveAction MoveUpCommand::getID() const {
        return MoveAction::MoveUp;
    } 
}
