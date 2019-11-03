#include <snake/Animator/Recorder.hpp>
#include <snake/Animator/NullAnimationMemento.hpp>

namespace snake::animator {

    Recorder::Recorder(physic::Body* body, sf::IntRect nullAnimationtextureRect)
    : body(body)
    , MIN_ANIMATIONS_AMOUNT(1) 
    , nullAnimationTextureRect( std::move(nullAnimationTextureRect) ) {
        animations.emplace_front( std::make_unique<NullAnimationMemento>(body, nullAnimationtextureRect) );
    }

    Animation<TextureRectangleMapper> const& Recorder::getPrevious() const {
        return *animations.back();
    }

    void Recorder::revertToPrevAnimation() {
        if (animations.size() > MIN_ANIMATIONS_AMOUNT) {
            animations.pop_front();
        }
    }
    
    Animation<TextureRectangleMapper> const& Recorder::getCurrent() const {
        return *animations.front();
    }

    void Recorder::record(TextureRectangleMapper const& mapperToRecord) {
        animations.pop_back();
        if ( mapperToRecord.isEmpty() ) {
            animations.emplace_front( std::make_unique<NullAnimationMemento>(body, nullAnimationTextureRect) );
        }else {
            animations.emplace_front( std::make_unique<AnimationMemento>(mapperToRecord) );
        }
    }

}
