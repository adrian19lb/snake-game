#ifndef CONSTANTMOVEMENTCOMPONENT_H
#define CONSTANTMOVEMENTCOMPONENT_H

#include <snake/Core/EntityComponentSystem/Component.hpp>

namespace snake::physic {

    class MoveCommand;

}


namespace snake::physic {

    struct ConstantMovementComponent : public core::Component<ConstantMovementComponent> {
        physic::MoveCommand* movement;
    };
}

#endif /* INPUTFLYWEIGHTCOMPONENT_H */
