#include <snake/Animator/States/BodyAnimationState.hpp>

namespace snake::animator {
    
    BodyAnimationState::BodyAnimationState(MultiStatesHandler<AnimationState>* stateManager, physic::Body* body, sf::IntRect const* bodyTextureRect)
    : AnimationState(stateManager)
    , body(body)
    , bodyTextureRect(bodyTextureRect) {
        
    }

    void BodyAnimationState::update(TextureRectangleMapper* mapper) {
        for (auto&& segment : *body) {
            mapper->add(segment.position, *bodyTextureRect); 
        }
            
    }

}
