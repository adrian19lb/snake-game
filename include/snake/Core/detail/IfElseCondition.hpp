#ifndef IFELSECONDITION_H
#define IFELSECONDITION_H

#include <functional>
#include <iostream>
namespace snake::core {

    template<typename T> 
    class IfElseConditionFunctor {
    public:
        IfElseConditionFunctor(std::function<T()>&& ifConditionFunctor, std::function<T()>&& elseConditionFunctor)
        : ifConditionFunctor(ifConditionFunctor)
        , elseConditionFunctor(elseConditionFunctor) {
        
        }

        T operator()() {
            if( condition() ) {
                return ifConditionFunctor();
            }else {
                return elseConditionFunctor();
            }
        }

    protected:
        virtual bool condition() = 0;
    private:
        std::function< T() > ifConditionFunctor;
        std::function< T() > elseConditionFunctor;
    };
}
    



#endif /* IFELSECONDITION_H */
