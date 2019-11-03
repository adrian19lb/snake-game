#include <snake/Animator/States/TailAnimationState.hpp>

namespace snake::animator {
    
    TailAnimationState::TailAnimationState(MultiStatesHandler<AnimationState>* stateManager, physic::Body* body, sf::IntRect const* tailTextureRect)
    : AnimationState(stateManager)
    , body(body)
    , tailTextureRect(tailTextureRect) {
        
    }

    void TailAnimationState::update(TextureRectangleMapper *mapper) {
            mapper->add(body->tail().position, *tailTextureRect);
        }

}
