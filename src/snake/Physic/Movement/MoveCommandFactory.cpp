#include <snake/Physic/Movement/MoveCommandFactory.hpp>
#include <snake/Physic/Movement/MoveState.hpp>
#include <snake/Physic/Movement/MoveStateFactory.hpp>
#include <snake/Physic/Movement/ChangedDirectionDetector.hpp>

namespace snake::physic {
        
    MoveCommandFactory::MoveCommandFactory()
    : lastAction(MoveAction::Unknow)
    , moveStateFactory(std::make_unique<MoveStateFactory>())
    , currentMoveState(moveStateFactory->createMoveState(lastAction, lastAction)) {
    
    }

    MoveCommandFactory::~MoveCommandFactory() {
    
    }

    MoveCommand* MoveCommandFactory::createMoveCommand(MoveAction action) {
        backUpLastMoveCommandID(); 
        changeStateIfActionChanged(action);

        return currentMoveState->createMoveCommand();
    }
    
    void MoveCommandFactory::backUpLastMoveCommandID() {
        auto currentMoveCommand = currentMoveState->createMoveCommand();
        lastAction = currentMoveCommand->getID();

    }

    void MoveCommandFactory::changeStateIfActionChanged(MoveAction action) {
        if (lastAction != action) {
            currentMoveState = moveStateFactory->createMoveState(action, lastAction);
        } 
    }

}
