#ifndef MOVERIGHTCOMMAND_H
#define MOVERIGHTCOMMAND_H
   
#include <snake/Physic/Movement/MoveCommand.hpp>

namespace snake::physic {

    class MoveRightCommand : public MoveCommand {
    public:
        void execute(MoveBehaviour* moveBehaviour, float dt) override;

        MoveAction getID() const override;
    };

}

#endif /* MOVERIGHTCOMMAND_H */
