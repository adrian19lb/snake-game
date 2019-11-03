#include <snake/Physic/BodyExtender/NearHeadBodyExtender.hpp>

namespace snake::physic {
        
    NearHeadBodyExtender::NearHeadBodyExtender(physic::Body* body)
    : BodyExtender(body)
    , body(body) {
        
    }

    void NearHeadBodyExtender::extendAt(sf::Vector2f const& position) {
        auto& head = body->cloneHead(); 
        head.position = position;
    }
    
    bool NearHeadBodyExtender::arePrevPhysicComponentCoordEqualWithCreated(SideOffsetCreator&& creator) const {
        auto const& segment = creator.getOffsetedPhysicComponent();

        return segment->prev && segment->prev->position == creator.createOffsetedPosition();
        
    }

}
