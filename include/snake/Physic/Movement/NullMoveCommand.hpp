#ifndef NULLMOVEMENTCOMMAND_H
#define NULLMOVEMENTCOMMAND_H

#include <snake/Physic/Movement/MoveCommand.hpp>

namespace snake::physic {

    class NullMoveCommand : public MoveCommand {
    public:
        void execute(MoveBehaviour* moveBehaviour, float dt) override;

        MoveAction getID() const override;
    };

}

#endif /* NULLMOVEMENTCOMMAND_H */
