#include <snake/Physic/Rotation/UnknownDirection.hpp>

namespace snake::physic {
        
    Direction::ID UnknownDirection::getID() const {
        return Direction::ID::Unknown; 
    }

}
