#ifndef RENDERCOMPONENTS_H
#define RENDERCOMPONENTS_H

#include <SFML/Graphics/Texture.hpp>
#include <snake/Core/EntityComponentSystem/Component.hpp>
#include <snake/Renderer/Model.hpp>

namespace snake::renderer {

    class RenderComponents : public core::Component<RenderComponents> {
    public:
        sf::Texture* texture;
        sf::IntRect const* textureRect;
        sf::Color fillColor = sf::Color(255,255,255,255);
        sf::Color outlineColor = sf::Color(255, 255, 255, 255);
    };

}

#endif /* RENDERCOMPONENTS_H */
