#ifndef TEXTURERECTFACTORY_H
#define TEXTURERECTFACTORY_H

#include <SFML/Graphics/Rect.hpp>
#include <map>

namespace snake::animator {
    
    template<typename Identifier, typename T>
    class TextureRectFactory {
    public:
        TextureRectFactory(sf::Vector2<T>&& textureSize)
        : textureSize(textureSize) {
        
        }

        void remove(Identifier id) {
            auto found = textureRectFactory.find(id);
            if (found != textureRectFactory.end()) {
                textureRectFactory.erase(found);
            }
        }

        void add(Identifier id, sf::Vector2<T>&& leftTopCoord) {
            textureRectFactory.emplace( std::make_pair(id, sf::Rect<T>(std::move(leftTopCoord), textureSize)) );
        }

        sf::Rect<T> const* create(Identifier id) const {
            return &textureRectFactory.at(id);
        }

    private:
        sf::Vector2<T> textureSize; 
        std::map<Identifier, sf::Rect<T> > textureRectFactory;
    };



}

#endif /* TEXTURERECTFACTORY_H */
