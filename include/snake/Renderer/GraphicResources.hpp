#ifndef GRAPHICRESOURCES_H
#define GRAPHICRESOURCES_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <snake/Core/EntityComponentSystem/Entity.hpp>
#include <snake/Core/ResourceHolder.hpp>
#include <snake/Animator/TextureRectFactory.hpp>
#include <snake/Animator/TextureRectID.hpp>

namespace snake::renderer {
        
    struct GraphicsResource {
        GraphicsResource(sf::RenderWindow* window, sf::Vector2i&& textureRectSize)
        : window(window)
        , textureRects( std::forward<sf::Vector2i>(textureRectSize) )
        , entitiesTextureRects(std::forward<sf::Vector2i>(textureRectSize)) {

        }

        sf::RenderWindow* window;        
        core::ResourceHolder<core::EntityID, sf::Texture> textures;
        animator::TextureRectFactory<animator::TextureRect, int> textureRects;
        animator::TextureRectFactory<core::EntityID, int> entitiesTextureRects;
    };


}



#endif /* GRAPHICRESOURCES_H */
