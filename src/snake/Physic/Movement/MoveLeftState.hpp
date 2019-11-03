#ifndef MOVELEFTSTATE_H
#define MOVELEFTSTATE_H

#include <snake/Physic/Movement/MoveState.hpp>

namespace snake::physic {
    
    class MoveLeftState : public MoveState {
    public:
        MoveLeftState(MoveAction lastAction);
    protected:
        MoveAction getActionID() const override;
    }; 
    
}

#endif /* MOVELEFTSTATE_H */
