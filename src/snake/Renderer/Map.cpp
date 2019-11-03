#include <snake/Renderer/Map.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <snake/Renderer/FileStreamReader.hpp>
#include <snake/Renderer/TitleCreator.hpp>

namespace snake::renderer {
    
    Map::Map(const sf::Texture*  texture, std::string txtMapFile) 
    : texture(texture)
    , txtMapFile(txtMapFile) {
        vertices.setPrimitiveType(sf::Quads);
    }

    void Map::create(sf::Vector2u tileSize) {
        FileStreamReader<int> streamReader(txtMapFile);
        for (unsigned row = 0; row < streamReader.size(); ++row) {
            for (unsigned col = 0; col < streamReader[row].size(); ++col) {
                int tilesNumber = streamReader[row][col];
                TitleCreator titleCreator(tileSize, texture);
                titleCreator.setVertexPosition(col,row);
                titleCreator.setTextureCoords(tilesNumber);
                appendTitle( titleCreator.getTitle() );
            }
        }
    }

    void Map::appendTitle(sf::Vertex const* title) {
        for (unsigned k = 0; k < 4; ++k) {
            vertices.append(title[k]);
        }
    }

    void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        states.transform *= getTransform();
        states.texture = texture;
        target.draw(vertices, states);
    }
}
