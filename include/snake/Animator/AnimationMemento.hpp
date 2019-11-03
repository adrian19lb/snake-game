#ifndef ANIMATIONMEMENTO_H
#define ANIMATIONMEMENTO_H

#include <snake/Animator/Animation.hpp>
#include <snake/Animator/TextureRectMapper.hpp>

namespace snake::animator {

    class AnimationMemento : public Animation<TextureRectangleMapper> {
    public:
        AnimationMemento(TextureRectangleMapper const& buffer);
        sf::IntRect const& getTextureRect(sf::Vector2f const& position) const override;
        TextureRectangleMapper::const_iterator begin() const override;
        TextureRectangleMapper::const_iterator end() const override;
        bool isEmpty() const override;
    protected:
        AnimationMemento() = default;
        void add(sf::Vector2f const& position, sf::IntRect const& texRect);
    private:
       TextureRectangleMapper mapper; 
    };

}


#endif /* ANIMATIONMEMENTO_H */
