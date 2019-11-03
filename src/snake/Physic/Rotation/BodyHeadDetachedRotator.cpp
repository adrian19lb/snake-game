#include <snake/Physic/Rotation/BodyDetachedHeadRotator.hpp>
#include <snake/Core/detail/IfElseCondition.hpp>

namespace snake::physic {
        
    BodyDetachedHeadRotator::BodyDetachedHeadRotator(Body* body)
    : BodyHeadRotator(body) {
        
    }
        
    std::unique_ptr< core::IfElseConditionFunctor<float> > BodyDetachedHeadRotator::createHeadDirectionState(Direction const& direction) {
        if (isHeadDetachedAcrossAxis() && direction != unknownDirection) {
            return BodyHeadRotator::createHeadDirectionState(unknownDirection);
        }else {
            return BodyHeadRotator::createHeadDirectionState(direction);
        }
    }
        
    bool BodyDetachedHeadRotator::isHeadDetachedAcrossAxis() const {
        return !isHeadNotDetachedAcrossX() && !isHeadNotDetachedAcrossY();
    }
        
    bool BodyDetachedHeadRotator::isHeadNotDetachedAcrossX() const {
        return getHeadSnapshot().position.x + getHeadSnapshot().size.x == getHeadSnapshot().prev->position.x ||
               getHeadSnapshot().position.x - getHeadSnapshot().size.x == getHeadSnapshot().prev->position.x;
    }

    bool BodyDetachedHeadRotator::isHeadNotDetachedAcrossY() const {
         return getHeadSnapshot().position.y + getHeadSnapshot().size.y == getHeadSnapshot().prev->position.y ||
                getHeadSnapshot().position.y - getHeadSnapshot().size.y == getHeadSnapshot().prev->position.y;
    }


}
