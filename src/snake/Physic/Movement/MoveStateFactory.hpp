#ifndef MOVESTATEFACTORY_H
#define MOVESTATEFACTORY_H

#include <snake/Physic/Movement/MoveAction.hpp>
#include <memory>

namespace snake::physic {
    
    class MoveState; 

    class MoveStateFactory {
    public:
        MoveStateFactory() = default;
        
        ~MoveStateFactory() = default;

       std::unique_ptr<MoveState> createMoveState(MoveAction currentAction, MoveAction lastAction) const;
    };

}

#endif /* MOVESTATEFACTORY_H */
