#include <snake/Animator/BodyStatesAnimator.hpp>
#include <snake/Animator/Recorder.hpp>
#include <snake/Animator/States/AnimationState.hpp>

namespace snake::animator {
    
    BodyStateAnimator::BodyStateAnimator(physic::Body* body, sf::IntRect nullAnimationRect)
    : body(body)
    , textureRectsMapper( new TextureRectangleMapper() )
    , animationRecorder( std::make_unique<Recorder>(body, nullAnimationRect) ) {

    }

    BodyStateAnimator::~BodyStateAnimator() {
        delete textureRectsMapper;
    }
    
    Animation<TextureRectangleMapper> const& BodyStateAnimator::getAnimation() const {
        return animationRecorder->getCurrent();
    }

    void BodyStateAnimator::animate() {
        textureRectsMapper->clear();
        animationStatesHandler.applyChanges();
        updateTextureRectMapperDependsIfLastAnimationChanged();
    }

    void BodyStateAnimator::updateTextureRectMapperDependsIfLastAnimationChanged() {
        if ( isAnimationChanged() ) {
            updateTextureRectMapperFromAnimationStates();
            animationRecorder->record(*textureRectsMapper);
        }
    }
    
    bool BodyStateAnimator::isAnimationChanged() const {
        try {
            auto const& previousAnimation = animationRecorder->getPrevious();
            previousAnimation.getTextureRect( body->head().position );
            return false;
        }catch(std::out_of_range const& exception) {
            return true;;
        }
    }

    void BodyStateAnimator::updateTextureRectMapperFromAnimationStates() {
        for (auto&& state : animationStatesHandler) {
            state->update(textureRectsMapper);
        }
    }

}
