#ifndef MOVERIGHTSTATE_H
#define MOVERIGHTSTATE_H

#include <snake/Physic/Movement/MoveState.hpp>

namespace snake::physic {
    
    class MoveRightState : public MoveState {
    public:
        MoveRightState(MoveAction lastAction);
    protected:
        MoveAction getActionID() const override;
    };

}

#endif /* MOVERIGHTSTATE_H */
