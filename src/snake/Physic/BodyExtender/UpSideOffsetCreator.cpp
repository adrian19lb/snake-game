#include <snake/Physic/BodyExtender/UpSideOffsetCreator.hpp>

namespace snake::physic {
        
    UpSideOffsetCreator::UpSideOffsetCreator(PhysicComponent* component)
    : SideOffsetCreator(component) {
        
    }

    sf::Vector2f UpSideOffsetCreator::createOffset() const {
        return sf::Vector2f(0.f, getPhysicComponentSize().y); 
    }

}
