#ifndef COLORCOMPONENTS_H
#define COLORCOMPONENTS_H

#include <snake/Core/Component.hpp>
#include <SFML/Graphics/Color.hpp>

namespace snake::renderer {
    
    struct ColorsComponent : public core::Component<ColorsComponent> {
        sf::Color fillColor = sf::Color();
        sf::Color outlineColor = sf::Color();
    };

}


#endif /* COLORCOMPONENTS_H */
