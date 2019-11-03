#include <snake/Animator/States/SpecificPositionAnimationState.hpp>

namespace snake::animator {

    SpecificPositionAnimationState::SpecificPositionAnimationState(MultiStatesHandler<AnimationState>* stateManager, sf::IntRect const* rect, sf::Vector2f position)
    : AnimationState(stateManager)
    , segmentPosition(position) 
    , textureRect(rect) {

    }

    void SpecificPositionAnimationState::update(TextureRectangleMapper* mapper)  {
        try {
            mapper->getTextureRect(segmentPosition);
            mapper->add(segmentPosition, *textureRect );
        }catch(std::out_of_range const& exception) {
            stateManager->pop(this);
        }
    }

}
