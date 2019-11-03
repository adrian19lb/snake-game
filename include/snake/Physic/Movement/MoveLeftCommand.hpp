#ifndef MOVELEFTCOMMAND_H
#define MOVELEFTCOMMAND_H

#include <snake/Physic/Movement/MoveCommand.hpp>

namespace snake::physic {
    
    class MoveLeftCommand : public MoveCommand {
    public:
        void execute(MoveBehaviour* moveBehaviour, float dt) override;

        MoveAction getID() const override;
    };
}



#endif /* MOVELEFTCOMMAND_H */
