#include <snake/Physic/BodyExtender/LeftSideOffsetCreator.hpp>

namespace snake::physic {
        
    LeftSideOffsetCreator::LeftSideOffsetCreator(PhysicComponent* segment)
    : SideOffsetCreator(segment) {
        
    }

    sf::Vector2f LeftSideOffsetCreator::createOffset() const {
        return sf::Vector2f( -SideOffsetCreator::getPhysicComponentSize().x, 0.f ); 
    }

}
