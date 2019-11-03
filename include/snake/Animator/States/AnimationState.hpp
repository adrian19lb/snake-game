#ifndef ANIMATIONSTATE_H
#define ANIMATIONSTATE_H

#include <snake/Animator/TextureRectMapper.hpp>
#include <snake/Core/MultiStatesHandler.hpp>

namespace snake::animator {

    class AnimationState {
    public:
        AnimationState(MultiStatesHandler<AnimationState>* stateManager);
        virtual void update(TextureRectangleMapper* mapper) = 0;
    protected:
        MultiStatesHandler<AnimationState>* stateManager;
    };
}


#endif /* ANIMATIONSTATE_H */
