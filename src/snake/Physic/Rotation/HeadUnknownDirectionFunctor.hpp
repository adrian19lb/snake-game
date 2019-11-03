#ifndef HEADUNKNOWNDIRECTIONFUNCTOR_H
#define HEADUNKNOWNDIRECTIONFUNCTOR_H

#include <snake/Core/detail/IfElseCondition.hpp>
#include <snake/Physic/PhysicComponent.hpp>

namespace snake::physic {
    
    template<typename T> 
    class HeadUnknownDirectionFunctor : public core::IfElseConditionFunctor<T> {
    public:
        template<typename PassIfFunctor, typename ElseFunctor>
        HeadUnknownDirectionFunctor(PhysicComponent* segment, PassIfFunctor ifFunctor, ElseFunctor elseFunctor)
        : core::IfElseConditionFunctor<T>( std::forward<PassIfFunctor>(ifFunctor), std::forward<ElseFunctor>(elseFunctor) ) 
        , segment(segment) {
        
        }
    protected:
        bool condition() override {
            return (segment->position.y == segment->prev->position.y) && (segment->position.x == segment->prev->position.x);
        }
    private:
       PhysicComponent* segment; 
    };



}

#endif /* HEADUNKNOWNDIRECTIONFUNCTOR_H */
