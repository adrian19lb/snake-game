#ifndef COLLISIONNOTIFIER_H
#define COLLISIONNOTIFIER_H

#include <snake/Core/EntityComponentSystem/Entity.hpp>

namespace snake::physic {
    
    class CollisionNotifier {
    public:
       virtual void notifyIfIsSpecificCollisionType(core::Entity *const entityWithSpecificComponent) = 0; 
    };
    
}

#endif /* COLLISIONNOTIFIER_H */
