#include <snake/Physic/Movement/UnknowDirectionDetector.hpp>

namespace snake::physic {
        
    UnknownDirectionDetector::UnknownDirectionDetector(MoveAction movementAction)
    : directionResponser(movementAction) {
        
    }

    bool UnknownDirectionDetector::isDirectionChanged() const {
        return directionResponser.existAction();
    }


}
