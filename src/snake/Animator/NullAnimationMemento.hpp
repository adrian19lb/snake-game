#ifndef NULLANIMATION_H
#define NULLANIMATION_H

#include <snake/Physic/Body.hpp>
#include <snake/Animator/AnimationMemento.hpp>

namespace snake::animator {

    class NullAnimationMemento : public AnimationMemento {
    public:
        NullAnimationMemento(physic::Body* body, sf::IntRect const& defaultTextureRect);
    };  


}
#endif /* NULLANIMATION_H */
