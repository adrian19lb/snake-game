#include <snake/Physic/BodyExtender/BodyExtender.hpp>
#include <stdexcept>

namespace snake::physic {
    
    BodyExtender::BodyExtender(Body* body)
    : body(body) {

    }

    void BodyExtender::extendFrom(SideOffsetCreator&& creator) {
        if (arePrevPhysicComponentCoordEqualWithCreated( std::forward<SideOffsetCreator>(creator))) {
            throw std::logic_error("Collision with previous segment in body!");        
        }else {
            extendAt(creator.createOffsetedPosition() );
        }
    }
    

}
