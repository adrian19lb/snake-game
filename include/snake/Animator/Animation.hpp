#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics/Rect.hpp>

namespace snake::animator {
    
    template<typename T>
    class Animation {
    public:
        using const_iterator = typename T::const_iterator;
    public:
        virtual sf::IntRect const& getTextureRect(sf::Vector2f const& position) const = 0;
        virtual const_iterator begin() const = 0;
        virtual const_iterator end() const = 0;
        virtual bool isEmpty() const = 0;
    };

}


#endif /* ANIMATION_H */
