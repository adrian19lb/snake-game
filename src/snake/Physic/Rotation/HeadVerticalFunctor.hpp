#ifndef HEADVERTICALFUNCTOR_H
#define HEADVERTICALFUNCTOR_H

#include <snake/Core/detail/IfElseCondition.hpp>
#include <snake/Physic/PhysicComponent.hpp>

namespace snake::physic {
    
    template<typename T> 
    class HeadVerticalFunctor : public core::IfElseConditionFunctor<T> {
    public:
        template<typename UpOrientationFunctor, typename DownOrientationFunctor>
        HeadVerticalFunctor(PhysicComponent* segment, UpOrientationFunctor first, DownOrientationFunctor second)
        : core::IfElseConditionFunctor<T>( std::forward<UpOrientationFunctor>(first), std::forward<DownOrientationFunctor>(second) ) 
        , segment(segment) {
        
        }
        
        bool condition() override {
            return (segment->position.y > segment->prev->position.y) && (segment->position.x == segment->prev->position.x); 
        }

    private:
       PhysicComponent* segment; 
    };

}


#endif /* HEADVERTICALFUNCTOR_H */
