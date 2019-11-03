#include <snake/Physic/Movement/MoveStateFactory.hpp>
#include <snake/Physic/Movement/MoveUpState.hpp>
#include <snake/Physic/Movement/MoveDownState.hpp>
#include <snake/Physic/Movement/MoveLeftState.hpp>
#include <snake/Physic/Movement/MoveRightState.hpp>
#include <snake/Physic/Movement/NullMoveState.hpp>
#include <snake/Physic/Movement/ChangedDirectionDetector.hpp>

namespace snake::physic {
        
    std::unique_ptr<MoveState> MoveStateFactory::createMoveState(MoveAction currentAction, MoveAction lastAction) const {
        switch (currentAction) {
            case MoveAction::MoveUp: 
                return std::make_unique<MoveUpState>(lastAction);
            case MoveAction::MoveDown:
                return std::make_unique<MoveDownState>(lastAction);
            case MoveAction::MoveLeft:
                return std::make_unique<MoveLeftState>(lastAction);
            case MoveAction::MoveRight:
                return std::make_unique<MoveRightState>(lastAction);
            case MoveAction::Unknow:
                return std::make_unique<NullMoveState>(lastAction);
        } 
    }

}
