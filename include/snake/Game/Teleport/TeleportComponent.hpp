#ifndef TELEPORTCOMPONENT_H
#define TELEPORTCOMPONENT_H

#include <SFML/System/Vector2.hpp>
#include <snake/Core/EntityComponentSystem/Component.hpp>

namespace snake::core {

    struct TeleportComponent : public Component<TeleportComponent> {
        sf::Vector2f position;
        
        TeleportComponent(sf::Vector2f position)
        : position(position) {
        
        }
    };
    
}

#endif /* TELEPORTCOMPONENT_H */
