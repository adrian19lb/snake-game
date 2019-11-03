#include <snake/Animator/States/HeadAnimationState.hpp>

namespace snake::animator {
        
    HeadAnimationState::HeadAnimationState(MultiStatesHandler<AnimationState>* stateManager, physic::Body* body, sf::IntRect const* headTextureRect)
    : AnimationState(stateManager)
    , body(body)
    , headTextureRect(headTextureRect) {
        
    }

    void HeadAnimationState::update(TextureRectangleMapper *mapper) {
        mapper->add(body->head().position, *headTextureRect);
    }

}
