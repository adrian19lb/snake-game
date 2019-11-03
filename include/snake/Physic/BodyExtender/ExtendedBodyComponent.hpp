#ifndef EXTENDEDBODYCOMPONENT_H
#define EXTENDEDBODYCOMPONENT_H

#include <snake/Core/EntityComponentSystem/Component.hpp>

namespace snake::physic {
    
    struct ExtendedBodyComponent : public core::Component<ExtendedBodyComponent> {
        int segmentsNumber = 1; 
    };

}

#endif /* EXTENDEDBODYCOMPONENT_H */
