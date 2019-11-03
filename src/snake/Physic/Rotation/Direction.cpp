#include <snake/Physic/Rotation/Direction.hpp>

namespace snake::physic {

    bool Direction::operator==(Direction const& direction) const {
        return getID() == direction.getID(); 
    }
    
    bool Direction::operator!=(Direction const& direction) const {
        return getID() != direction.getID(); 
    }

}
