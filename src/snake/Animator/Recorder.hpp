#ifndef RECORDER_H
#define RECORDER_H

#include <snake/Physic/Body.hpp>
#include <snake/Animator/Animation.hpp>
#include <snake/Animator/TextureRectMapper.hpp>
#include <deque>
#include <memory>

namespace snake::animator {
    
    class Recorder {
    public:
        template<typename T> using AnimationUPtr = std::unique_ptr< Animation<T> >;
        sf::IntRect nullAnimationTextureRect;
    public:
        Recorder(physic::Body* body, sf::IntRect nullAnimationTextureRect = sf::IntRect(0,0,0,0));
        Animation<TextureRectangleMapper> const& getPrevious() const;
        void revertToPrevAnimation();
        Animation<TextureRectangleMapper> const& getCurrent() const;
        void record(TextureRectangleMapper const& mapperToRecord);
    private:
        physic::Body* body;
        const size_t MIN_ANIMATIONS_AMOUNT;
        sf::IntRect nullAnimationtextureRect;
        std::deque< AnimationUPtr<TextureRectangleMapper> > animations;
    };

}


#endif /* RECORDER_H */
