#include <snake/Physic/BodyExtender/NearTailBodyExtender.hpp>

namespace snake::physic {
        
    NearTailBodyExtender::NearTailBodyExtender(physic::Body* body)
    : BodyExtender(body)
    , body(body) {
        
    }

    void NearTailBodyExtender::extendAt(sf::Vector2f const& position) {
        auto& tail = body->cloneTail(); 
        tail.position = position;
    }
    
    bool NearTailBodyExtender::arePrevPhysicComponentCoordEqualWithCreated(SideOffsetCreator&& creator) const {
        return body->tail().next && body->tail().next->position == creator.createOffsetedPosition();        
    }

}
