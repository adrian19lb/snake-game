#ifndef BODYSTATEANIMATOR_H
#define BODYSTATEANIMATOR_H

#include <snake/Animator/Animation.hpp>
#include <snake/Animator/TextureRectMapper.hpp>
#include <snake/Animator/Animator.hpp>
#include <snake/Physic/Body.hpp>
#include <snake/Core/MultiStatesHandler.hpp>

namespace snake::animator {
    
    class Recorder;
    class AnimationState;

    class BodyStateAnimator : public Animator {
    public:
        BodyStateAnimator(physic::Body* body, sf::IntRect nullAnimationRect = sf::IntRect(0,0,0,0));
        
        ~BodyStateAnimator();    
            
        Animation<TextureRectangleMapper> const& getAnimation() const override;
        
        template<typename AnimationStateType, typename... Args> void push(Args... args) {
            animationStatesHandler.push<AnimationStateType>(std::forward<Args>(args)... );
        }

        void animate() override;
    private:
        void updateTextureRectMapperDependsIfLastAnimationChanged();
        bool isAnimationChanged() const;
        void updateTextureRectMapperFromAnimationStates();
    private:
        physic::Body* body;
        TextureRectangleMapper* textureRectsMapper;
        std::unique_ptr<Recorder> animationRecorder;
        MultiStatesHandler<AnimationState> animationStatesHandler;
    };
}
#endif /* BODYANIMATOR_H */
