#ifndef MOVEDOWNCOMMAND_H
#define MOVEDOWNCOMMAND_H

#include <snake/Physic/Movement/MoveCommand.hpp>

namespace snake::physic {
    
    class MoveDownCommand : public MoveCommand {
    public:
        void execute(MoveBehaviour* moveBehaviour, float dt) override;

        MoveAction getID() const override;
    };

}



#endif /* MOVEDOWNCOMMAND_H */
