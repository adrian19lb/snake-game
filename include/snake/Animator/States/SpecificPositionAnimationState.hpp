#ifndef SPECIFIC_POSITION_ANIMATION_STATE_H
#define SPECIFIC_POSITION_ANIMATION_STATE_H

#include <snake/Animator/States/AnimationState.hpp>
#include <snake/Physic/Body.hpp>

namespace snake::animator {

    class SpecificPositionAnimationState : public AnimationState {
    public:
        SpecificPositionAnimationState(MultiStatesHandler<AnimationState>* stateManager, sf::IntRect const* rect, sf::Vector2f position);
        void update(TextureRectangleMapper* mapper) override;
    private:
        sf::Vector2f segmentPosition;
        sf::IntRect const* textureRect;
    };

}

#endif /* SPECIFICPOSITIONANIMATIONSTATE_H */
