#include <snake/Physic/Movement/DirectionResponser.hpp>

namespace snake::physic {
       
    DirectionResponser::DirectionResponser(MoveAction movementAction)
    : movementAction(movementAction) {
       
    }

    bool DirectionResponser::isVertical() const {
        return movementAction == MoveAction::MoveUp || movementAction == MoveAction::MoveDown;
    }

    bool DirectionResponser::isHorizontal() const {
        return movementAction == MoveAction::MoveLeft || movementAction == MoveAction::MoveRight;
    }

    bool DirectionResponser::existAction() const {
        return movementAction == MoveAction::Unknow; 
    }


}
