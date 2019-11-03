#ifndef BODYANIMATIONSTATE_H
#define BODYANIMATIONSTATE_H

#include <snake/Animator/States/AnimationState.hpp>
#include <snake/Physic/Body.hpp>

namespace snake::animator {
    
    class BodyAnimationState : public AnimationState {
    public:
        BodyAnimationState(MultiStatesHandler<AnimationState>* stateManager, physic::Body* body, sf::IntRect const* bodyTextureRect);
        void update(TextureRectangleMapper* mapper);
    private:
       physic::Body* body;
       sf::IntRect const* bodyTextureRect;
    };

}

#endif /* BODYANIMATIONSTATE_H */
