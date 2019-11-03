#include <snake/Physic/BodyExtender/DownSideOffsetCreator.hpp>

namespace snake::physic {
        
    DownSideOffsetCreator::DownSideOffsetCreator(PhysicComponent* segment)
    : SideOffsetCreator(segment) {
        
    }

    sf::Vector2f DownSideOffsetCreator::createOffset() const {
        return sf::Vector2f(0.f, -getPhysicComponentSize().y); 
    }

}
