#ifndef TEXTURESCOMPONENT_H
#define TEXTURESCOMPONENT_H

#include <snake/Core/Component.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace snake::renderer {

    struct TexturesComponent {
        sf::Texture* texture;
        sf::IntRect const* textureRect;
    };

}

#endif /* TEXTURESCOMPONENT_H */
