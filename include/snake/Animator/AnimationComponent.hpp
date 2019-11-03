#ifndef ANIMATIONCOMPONENT_H
#define ANIMATIONCOMPONENT_H

#include <snake/Animator/Animation.hpp>
#include <snake/Animator/TextureRectMapper.hpp>
#include <snake/Core/EntityComponentSystem/Component.hpp>

namespace  snake::animator {

    struct AnimationComponent : public core::Component<AnimationComponent> {
        Animation<TextureRectangleMapper> const* animation; 
    };

}

#endif /* ANIMATIONCOMPONENT_H */
