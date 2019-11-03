#ifndef PHYSICCOMPONENT_H
#define PHYSICCOMPONENT_H

#include <SFML/System/Vector2.hpp>

namespace snake::physic {
        
    struct PhysicComponent {
        
        sf::Vector2f position;
        sf::Vector2f origin;
        float angle;
        sf::Vector2f size;

        PhysicComponent* prev;
        PhysicComponent* next;

        PhysicComponent(sf::Vector2f&& size);
        PhysicComponent(PhysicComponent const& component);
        PhysicComponent(PhysicComponent&& component);

        PhysicComponent& operator=(PhysicComponent&& component);
        PhysicComponent clone();
    };

}

#endif /* PHYSICCOMPONENT_H */
