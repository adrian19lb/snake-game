#include <snake/Animator/TextureRectMapper.hpp>

namespace snake::animator {

    void TextureRectangleMapper::add(sf::Vector2f const& segmentPosition, sf::IntRect const& textureRect) {
        if ( auto found = textureRectMapper.find(segmentPosition); found != textureRectMapper.end() ) {
            textureRectMapper.at(segmentPosition) = sf::IntRect(textureRect);
        }else {
            textureRectMapper.emplace( std::make_pair(segmentPosition, textureRect) );
        }
    }

    void TextureRectangleMapper::clear() {
        textureRectMapper.clear();
    }

    TextureRectangleMapper::const_iterator TextureRectangleMapper::begin() const {
        return textureRectMapper.begin();
    }

    TextureRectangleMapper::const_iterator TextureRectangleMapper::end() const {
        return textureRectMapper.end(); 
    }

    bool TextureRectangleMapper::isEmpty() const {
        return textureRectMapper.empty();
    }

    const sf::IntRect& TextureRectangleMapper::getTextureRect(sf::Vector2f const& segmentPosition) const {
        return textureRectMapper.at(segmentPosition);
    }

    void TextureRectangleMapper::fillFrom(TextureRectangleMapper const& sourceBuffer) {
        for (auto&& i : sourceBuffer.textureRectMapper) {
            add(i.first, i.second);
        }
    
    }
}
