#ifndef MOVECOMMAND_H
#define MOVECOMMAND_H

#include <snake/Physic/Movement/MoveAction.hpp>

namespace snake::physic {
    
    class MoveBehaviour;

    class MoveCommand {
    public:
        virtual ~MoveCommand() = default;

        virtual void execute(MoveBehaviour* moveBehaviour, float dt) = 0;

        virtual MoveAction getID() const = 0;
    };



}

#endif /* MOVECOMMAND_H */
