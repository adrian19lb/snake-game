#ifndef MOVEUPSTATE_H
#define MOVEUPSTATE_H

#include <snake/Physic/Movement/MoveState.hpp>

namespace snake::physic {
    
    class MoveUpState : public MoveState {
    public:
        MoveUpState(MoveAction lastAction); 
    protected:
        MoveAction getActionID() const override;
    };
}

#endif /* MOVEUPSTATE_H */
