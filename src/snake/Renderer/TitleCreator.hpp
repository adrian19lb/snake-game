#ifndef TITLECREATOR_H
#define TITLECREATOR_H

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Texture.hpp>

namespace snake::renderer {

    class TitleCreator {
    public:
        TitleCreator(sf::Vector2u size, const sf::Texture* texture);
        void setVertexPosition(int x, int y);
        void setTextureCoords(int titleNumber);
    private:
        sf::Vector2f getTextureRectPosition(int titleNumber) const;
    public:
        sf::Vertex const* getTitle() const;
    private:
        sf::Vector2u size;
        const sf::Texture* texture;
        sf::Vertex quad[4];
    };

}


#endif /* TITLECREATOR_H */
