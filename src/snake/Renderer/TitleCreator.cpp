#include <snake/Renderer/TitleCreator.hpp>

namespace snake::renderer {
        
    TitleCreator::TitleCreator(sf::Vector2u size, const sf::Texture* texture)
    : size(size)
    , texture(texture) {
        
    }

    void TitleCreator::setVertexPosition(int x, int y) {
        quad[0].position = sf::Vector2f(x * size.x, y*size.y);
        quad[1].position = sf::Vector2f((x + 1) * size.x, y * size.y);
        quad[2].position = sf::Vector2f( (x + 1) * size.x, (y + 1) * size.y);
        quad[3].position = sf::Vector2f( x * size.x, (y + 1) * size.y);
    }

    void TitleCreator::setTextureCoords(int titleNumber) {
        auto textureCoords = getTextureRectPosition(titleNumber);
        quad[0].texCoords = sf::Vector2f(textureCoords.x * size.x, textureCoords.y*size.y);
        quad[1].texCoords = sf::Vector2f((textureCoords.x + 1) * size.x, textureCoords.y*size.y);
        quad[2].texCoords = sf::Vector2f((textureCoords.x + 1) * size.x, (textureCoords.y + 1)*size.y);
        quad[3].texCoords = sf::Vector2f(textureCoords.x * size.x, (textureCoords.y + 1)*size.y);
    }
    
    sf::Vector2f TitleCreator::getTextureRectPosition(int titleNumber) const {
        int tu = titleNumber % (texture->getSize().x / size.x);
        int tv = titleNumber / (texture->getSize().x / size.x);

        return sf::Vector2f(tu, tv);
    }



    sf::Vertex const* TitleCreator::getTitle() const {
        return quad; 
    }

}
