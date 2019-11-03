#include <snake/Animator/AnimationMemento.hpp>

namespace snake::animator {
    
    AnimationMemento::AnimationMemento(TextureRectangleMapper const& buffer) {
            this->mapper.fillFrom(buffer);
    }

    sf::IntRect const& AnimationMemento::getTextureRect(sf::Vector2f const& position) const {
            return mapper.getTextureRect(position); 
    }

    TextureRectangleMapper::const_iterator AnimationMemento::begin() const {
        return mapper.begin(); 
    }

    TextureRectangleMapper::const_iterator AnimationMemento::end() const {
        return mapper.end();
    }

    bool AnimationMemento::isEmpty() const {
        return mapper.isEmpty();
    }
    
    void AnimationMemento::add(sf::Vector2f const& position, sf::IntRect const& texRect) {
        mapper.add(position, texRect); 
    }
}
