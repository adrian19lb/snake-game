#include <SFML/Graphics/Rect.hpp>
#include <snake/Physic/Collision/BodyCollisionDetector.hpp>

namespace snake::physic {
        
    BodyCollisionDetector::BodyCollisionDetector(Body* body)
    : body(body) {
        
    }

    bool BodyCollisionDetector::isAnyPhysicComponentOverlapedIn(Body* collidable) {
        return isOverlaped(&body->head(), &collidable->head());
    }
        
    bool BodyCollisionDetector::isOverlaped(PhysicComponent* lhs, PhysicComponent* rhs) {
        while(lhs) {
            return checkCollisionForEachLhsPhysicComponent(lhs, rhs);
        }

        return chackAgainCollisionForPrevPhysicComponentIfFinishIteration(lhs, rhs);
    }

    bool BodyCollisionDetector::checkCollisionForEachLhsPhysicComponent(PhysicComponent* lhs, PhysicComponent* rhs) {
        if ( !sf::Rect<float>(lhs->position, sf::Vector2f(lhs->size.x, -lhs->size.y)).intersects(sf::Rect<float>(rhs->position, sf::Vector2f(rhs->size.x, -rhs->size.y)))) {
            return isOverlaped(lhs->prev, rhs);
        }else {
            return true;
        }
    }

    bool BodyCollisionDetector::chackAgainCollisionForPrevPhysicComponentIfFinishIteration(PhysicComponent* lhs, PhysicComponent* rhs) {
        if (!lhs && rhs->prev) {
            return isOverlaped(&body->head(), rhs->prev);
        }else {
            return false;
        }
    }

}
