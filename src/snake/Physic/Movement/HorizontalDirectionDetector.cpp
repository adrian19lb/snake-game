#include <snake/Physic/Movement/HorizontalDirectionDetector.hpp>

namespace snake::physic {

    HorizontalDirectionDetector::HorizontalDirectionDetector(MoveAction movementAction)
    : responser(movementAction) {
        
    }

    bool HorizontalDirectionDetector::isDirectionChanged() const {
        return responser.isVertical() || responser.existAction(); 
    }

}
