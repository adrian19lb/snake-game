#ifndef HEADANIMATIONSTATE_H
#define HEADANIMATIONSTATE_H

#include <snake/Animator/States/AnimationState.hpp>
#include <snake/Physic/Body.hpp>

namespace snake::animator {
    
    class HeadAnimationState : public AnimationState {
    public:
        HeadAnimationState(MultiStatesHandler<AnimationState>* stateManager, physic::Body* body, sf::IntRect const* headTextureRect);
        void update(TextureRectangleMapper *mapper) override;
    private:
        physic::Body* body;
        sf::IntRect const* headTextureRect;
    };

}

#endif /* HEADANIMATIONSTATE_H */
