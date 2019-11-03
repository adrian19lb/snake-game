#ifndef MODEL_H
#define MODEL_H

#include <SFML/Graphics/Drawable.hpp>
#include <snake/Animator/Animation.hpp>
#include <snake/Animator/TextureRectMapper.hpp>
#include <memory>

namespace sf {
    class Color;
}

namespace snake::renderer {
    
    class Model : public sf::Drawable  {
    public:
        virtual void setColor(sf::Color const& color) = 0;
        virtual void setAnimation(animator::Animation<animator::TextureRectangleMapper> const& animation) = 0;
        virtual void setAnimation(sf::IntRect const& textureRect) = 0;
        virtual void setTexture(const sf::Texture* texture, bool resetRect = false) = 0;
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override = 0;
    };

    using ModelUPtr = std::unique_ptr<Model>;

}

#endif /* MODEL_H */
