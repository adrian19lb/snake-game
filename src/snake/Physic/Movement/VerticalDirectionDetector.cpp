#include <snake/Physic/Movement/VerticalDirectionDetector.hpp>

namespace snake::physic {
        
    VerticalDirectionDetector::VerticalDirectionDetector(MoveAction movementAction)
    : responser(movementAction) {
        
    }

    bool VerticalDirectionDetector::isDirectionChanged() const {
        return responser.isHorizontal() || responser.existAction(); 
    }


}
