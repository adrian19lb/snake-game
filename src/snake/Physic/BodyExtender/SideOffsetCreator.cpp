#include <snake/Physic/BodyExtender/SideOffsetCreator.hpp>

namespace snake::physic {
        
    SideOffsetCreator::SideOffsetCreator(PhysicComponent* component)
    : component(component) {
        
    }

    PhysicComponent* SideOffsetCreator::getOffsetedPhysicComponent() const {
        return component; 
    }

    sf::Vector2f SideOffsetCreator::createOffsetedPosition() const {
        return component->position + createOffset();
    }
    
    sf::Vector2f const& SideOffsetCreator::getPhysicComponentSize() const {
        return  component->size;
    }


}
