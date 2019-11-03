#include <snake/Game/Teleport/TeleportAcrossAxisComponent.hpp>

namespace snake::game {
        
    TeleportAcrossAxsisComponent::Axis::Axis(float value)
    : value(value) {
            
    }

    TeleportAcrossAxsisComponent::X::X(float dx)
    : Axis(dx) {
            
    }

    sf::Vector2f TeleportAcrossAxsisComponent::X::transform(sf::Vector2f position) const {
        return sf::Vector2f(value, position.y);
    }

    TeleportAcrossAxsisComponent::Y::Y(float dy)
    : Axis(dy) {

    }

    sf::Vector2f TeleportAcrossAxsisComponent::Y::transform(sf::Vector2f position) const {
        return sf::Vector2f(position.x, value);
    }
        
    TeleportAcrossAxsisComponent::TeleportAcrossAxsisComponent(Axis* axis)
    : axis(axis) {

    }

    TeleportAcrossAxsisComponent::~TeleportAcrossAxsisComponent() {
        delete axis;
     }

}
