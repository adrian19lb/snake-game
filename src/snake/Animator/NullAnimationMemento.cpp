#include <snake/Animator/NullAnimationMemento.hpp>

namespace snake::animator {
        
    NullAnimationMemento::NullAnimationMemento(physic::Body* body, sf::IntRect const& defaultTextureRect)
    : AnimationMemento() {
        for (auto&& segment : *body) {
            AnimationMemento::add(segment.position, defaultTextureRect); 
        }
    }

}
