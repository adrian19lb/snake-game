#ifndef BODYCOLLISIONCOMPONENT_H
#define BODYCOLLISIONCOMPONENT_H

#include <snake/Physic/Body.hpp>

namespace snake::physic {
    
    class BodyCollisionDetector {
    public:
        BodyCollisionDetector(Body* body);

        bool isAnyPhysicComponentOverlapedIn(Body* collidable);
    private:
        bool isOverlaped(PhysicComponent* lhs, PhysicComponent* rhs);

        bool checkCollisionForEachLhsPhysicComponent(PhysicComponent* lhs, PhysicComponent* rhs);

        bool chackAgainCollisionForPrevPhysicComponentIfFinishIteration(PhysicComponent* lhs, PhysicComponent* rhs);
    private:
        Body* body;
    };


}

#endif /* BODYCOLLISIONCOMPONENT_H */
