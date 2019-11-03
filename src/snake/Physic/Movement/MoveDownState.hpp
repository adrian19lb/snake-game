#ifndef MOVEDOWNSTATE_H
#define MOVEDOWNSTATE_H

#include <snake/Physic/Movement/MoveState.hpp>

namespace snake::physic {
    
    class MoveDownState : public MoveState {
    public:
        MoveDownState(MoveAction lastAction);
    protected:
       MoveAction getActionID() const override;
    };
}

#endif /* MOVEDOWNSTATE_H */
