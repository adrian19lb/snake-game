#ifndef ANIMATOR_H
#define ANIMATOR_H

#include <snake/Animator/Animation.hpp>
#include <snake/Animator/TextureRectMapper.hpp>

namespace snake::animator {
    
    class Animator {
    public:
       virtual ~Animator() = default;
       virtual void animate() = 0;
       virtual Animation<TextureRectangleMapper> const& getAnimation() const = 0; 
    };

}

#endif /* ANIMATOR_H */
