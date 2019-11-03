#include <snake/Physic/BodyExtender/RightSideOffsetCreator.hpp>

namespace snake::physic {
        
    RightSideOffsetCreator::RightSideOffsetCreator(PhysicComponent* segment)
    : SideOffsetCreator(segment) {
        
    }

    sf::Vector2f RightSideOffsetCreator::createOffset() const  {
        return sf::Vector2f( SideOffsetCreator::getPhysicComponentSize().x, 0.f ); 
    }

}
