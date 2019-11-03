#include <snake/Physic/Rotation/OrthogonalDirectionResponser.hpp>
#include <snake/Physic/Rotation/Horizontal.hpp>
#include <snake/Physic/Rotation/Vertical.hpp>
#include <snake/Physic/Rotation/UnknownDirection.hpp>
#include <iostream>

namespace snake::physic {

    OrthogonalDirectionResponser::OrthogonalDirectionResponser(PhysicComponent* segment)
    : segment(segment) {
        
    }

    std::unique_ptr<Direction> OrthogonalDirectionResponser::response() const {
        if (segment->prev) {
            return createDirectionIfPrevPhysicComponentExist();
        }else {
            return std::make_unique<UnknownDirection>();
        }
    }
    
    std::unique_ptr<Direction> OrthogonalDirectionResponser::createDirectionIfPrevPhysicComponentExist() const {
        if ( isHorizontalLayout(*segment, *segment->prev) ) {
            return std::make_unique<Horizontal>();
        }else  if( isVerticalLayout(*segment, *segment->prev) ){
            return std::make_unique<Vertical>();
        }else {
            return std::make_unique<UnknownDirection>();
        }
    
    }
    
    bool OrthogonalDirectionResponser::isHorizontalLayout(PhysicComponent const& current, physic::PhysicComponent const& previous) const {
        return (current.position.y == previous.position.y) && (current.position.x != previous.position.x);
    }
        
    bool OrthogonalDirectionResponser::isVerticalLayout(PhysicComponent const& current, physic::PhysicComponent const& previous) const {
        return (current.position.x == previous.position.x) && (current.position.y != previous.position.y); 
    }

}
