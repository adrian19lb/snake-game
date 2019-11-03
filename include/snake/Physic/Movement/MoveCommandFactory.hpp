#ifndef MOVECOMMANDFACTORY_H
#define MOVECOMMANDFACTORY_H

#include <memory>
#include <snake/Physic/Movement/MoveAction.hpp>
#include <snake/Physic/Movement/MoveCommand.hpp>

namespace snake::physic {
    
    class MoveState;
    class MoveStateFactory;

    class MoveCommandFactory {
    public:
        MoveCommandFactory();

        ~MoveCommandFactory();

        MoveCommand* createMoveCommand(MoveAction action);
    private:
        void backUpLastMoveCommandID();

        void changeStateIfActionChanged(MoveAction action);
    private:
        MoveAction lastAction;
        std::unique_ptr<MoveStateFactory> moveStateFactory;
        std::unique_ptr<MoveState> currentMoveState;
    };

}


#endif /* MOVECOMMANDFACTORY_H */
