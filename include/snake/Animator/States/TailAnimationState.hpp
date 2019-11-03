#ifndef TAILANIMATIONSTATE_H
#define TAILANIMATIONSTATE_H

#include <snake/Animator/States/AnimationState.hpp>
#include <snake/Physic/Body.hpp>

namespace snake::animator {
    
    class TailAnimationState : public AnimationState {
    public:
        TailAnimationState(MultiStatesHandler<AnimationState>* stateManager, physic::Body* body, sf::IntRect const* tailTextureRect);
        void update(TextureRectangleMapper *mapper) override;
    private:
        physic::Body* body;
        sf::IntRect const* tailTextureRect;
    };

}

#endif /* TAILANIMATIONSTATE_H */
