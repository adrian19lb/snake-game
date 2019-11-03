#ifndef NULLMOVEMENTSTATE_H
#define NULLMOVEMENTSTATE_H

#include <snake/Physic/Movement/MoveState.hpp>

namespace snake::physic {
    
    class NullMoveState : public MoveState {
    public:
        NullMoveState(MoveAction lastAction);
    protected:
         MoveAction getActionID() const override;
    };

}

#endif /* NULLMOVEMENTSTATE_H */
