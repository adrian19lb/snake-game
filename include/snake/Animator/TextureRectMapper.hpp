#ifndef TEXTURERECTMAPPER_H
#define TEXTURERECTMAPPER_H

#include <SFML/Graphics/Rect.hpp>
#include <unordered_map>

namespace snake::animator {

    class TextureRectangleMapper {
        
        struct PositionHasher {
            size_t operator()(const sf::Vector2f& position) const {
               size_t hashX = std::hash<float>{}(position.x);
               size_t hashY = std::hash<float>{}(position.y);
               return hashX ^ (hashY << 1);
            } 
        };

    public:
        using const_iterator = std::unordered_map<sf::Vector2f, sf::IntRect, PositionHasher>::const_iterator;
    public:
        void add(sf::Vector2f const& segmentPosition, sf::IntRect const& textureRect);
        void clear();
        const_iterator begin() const;
        const_iterator end() const;
        bool isEmpty() const;
        const sf::IntRect& getTextureRect(sf::Vector2f const& segmentPosition) const;
        void fillFrom(TextureRectangleMapper const& sourceBuffer);
    private:
        std::unordered_map<sf::Vector2f, sf::IntRect, PositionHasher> textureRectMapper;
    };


}

#endif /* TEXTURERECTMAPPER_H */
