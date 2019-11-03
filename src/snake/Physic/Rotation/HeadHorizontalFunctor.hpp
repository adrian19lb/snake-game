#ifndef HEADHORIZONTALFUNCTOR_H
#define HEADHORIZONTALFUNCTOR_H

#include <snake/Core/detail/IfElseCondition.hpp>
#include <snake/Physic/PhysicComponent.hpp>
#include <iostream>

namespace snake::physic {
    
    template<typename T>
    class HeadHorizontalFunctor : public core::IfElseConditionFunctor<T> {
    public:
        template<typename RightHeadOrientationFunctor, typename LeftHeadOrientationFunctor>
        HeadHorizontalFunctor(PhysicComponent* segment, LeftHeadOrientationFunctor first, RightHeadOrientationFunctor second)
        : core::IfElseConditionFunctor<T>( std::forward<LeftHeadOrientationFunctor>(first), std::forward<RightHeadOrientationFunctor>(second) ) 
        , segment(segment) {
        
        }

    protected:
        bool condition() override {
            return (segment->position.x > segment->prev->position.x) && (segment->position.y == segment->prev->position.y); 
        }
    private:
       PhysicComponent* segment; 
    };


}


#endif /* HEADHORIZONTALFUNCTOR_H */
