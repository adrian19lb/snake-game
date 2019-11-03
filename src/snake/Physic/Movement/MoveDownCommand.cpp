#include <snake/Physic/Movement/MoveDownCommand.hpp>
#include <snake/Physic/Movement/MoveBehaviour.hpp>

namespace snake::physic {
        
    void MoveDownCommand::execute(MoveBehaviour* moveBehaviour, float dt) {
        moveBehaviour->moveDown(dt); 
    }

    MoveAction MoveDownCommand::getID() const {
        return MoveAction::MoveDown;
    } 

}
