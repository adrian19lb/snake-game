#ifndef MOVEUPCOMMAND_H
#define MOVEUPCOMMAND_H

#include <snake/Physic/Movement/MoveCommand.hpp>

namespace snake::physic {
    
    class MoveUpCommand : public MoveCommand {
    public:
      void execute(MoveBehaviour* moveBehaviour, float dt) override;

      MoveAction getID() const override;
    };

}

#endif /* MOVEUPCOMMAND_H */
