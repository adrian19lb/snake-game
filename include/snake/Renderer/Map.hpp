#ifndef MAP_HPP_INCLUDED
#define MAP_HPP_INCLUDED

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <string>

namespace snake::renderer {
    
    class Map : public sf::Drawable, public sf::Transformable {
    public:
        Map(const sf::Texture* texture, std::string txtMapFile); 
        void create(sf::Vector2u tileSize);
    private:
        void appendTitle(sf::Vertex const* title);
        void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        const sf::Texture* texture;
        sf::VertexArray vertices;
        std::string txtMapFile;
    };
}
#endif // MAP_HPP_INCLUDED
