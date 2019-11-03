#include <snake/Physic/Rotation/BodyHeadRotator.hpp>
#include <snake/Physic/Rotation/OrthogonalDirectionResponser.hpp>
#include <snake/Physic/Rotation/HeadHorizontalFunctor.hpp>
#include <snake/Physic/Rotation/HeadVerticalFunctor.hpp>
#include <snake/Physic/Rotation/HeadUnknownDirectionFunctor.hpp>
#include <snake/Physic/Rotation/Direction.hpp>
#include <iostream>
#include <snake/Physic/Rotation/UnknownDirection.hpp>

namespace snake::physic {
    
    BodyHeadRotator::BodyHeadRotator(Body* body)
    : body(body)
    , headSnapshot( body->head() )
    , DIRECTION_CONDITION_AMOUNT(3)
    , rotator(DIRECTION_CONDITION_AMOUNT) {
        registerRotationAngles();
    }

    void BodyHeadRotator::setBodyHeadAsPreviousPhysicComponentForHeadSnapshot() {
        headSnapshot.prev = &body->head();
    }

    void BodyHeadRotator::registerRotationAngles() {
        rotator[Direction::ID::Horizontal] = std::pair( [](){ return -180.f; }, [](){ return 0.f; } );
        rotator[Direction::ID::Vertical] = std::pair( [](){ return 90.f; }, [](){ return -90.f; } );
        rotator[Direction::ID::Unknown] = std::pair( [this](){ return body->head().angle; }, 
                                                     [this](){ return body->head().angle; } );
    }
    
    float BodyHeadRotator::getAngle() {
        float angle = getAngleDependsOfDirection();
        createHeadSnapshot();

        return angle;
    }
    
    void BodyHeadRotator::createHeadSnapshot() {
        headSnapshot = PhysicComponent(body->head());
    }

    
    PhysicComponent const& BodyHeadRotator::getHeadSnapshot() const {
        return headSnapshot;
    }

    float BodyHeadRotator::getAngleDependsOfDirection() {
        OrthogonalDirectionResponser responser(&headSnapshot);
        setBodyHeadAsPreviousPhysicComponentForHeadSnapshot();
        auto direction = responser.response();

        // if (!isHeadDetachedAcrossY() && !isHeadDetachedAcrossX() && direction->getID() != Direction::Unknown) {
        //     direction = std::make_unique<UnknownDirection>();
        // }

        auto headRotationDirectionState = createHeadDirectionState(*direction);
                
        return headRotationDirectionState->operator()();
    }

    // bool BodyHeadRotator::isHeadDetachedAcrossX() const {
    //     return headSnapshot.position.x + headSnapshot.size.x == headSnapshot.prev->position.x ||
    //            headSnapshot.position.x - headSnapshot.size.x == headSnapshot.prev->position.x;
    // }
    //
    // bool BodyHeadRotator::isHeadDetachedAcrossY() const {
    //     return headSnapshot.position.y + headSnapshot.size.y == headSnapshot.prev->position.y ||
    //            headSnapshot.position.y - headSnapshot.size.y == headSnapshot.prev->position.y;
    // }

    std::unique_ptr< core::IfElseConditionFunctor<float> > BodyHeadRotator::createHeadDirectionState(Direction const& direction) {
        switch( direction.getID() ) {
            case Direction::ID::Horizontal:
                return std::make_unique< HeadHorizontalFunctor<float> >( &headSnapshot, rotator[direction.getID()].first, rotator[direction.getID()].second );
            case Direction::ID::Vertical:
                return std::make_unique< HeadVerticalFunctor<float> >( &headSnapshot, rotator[direction.getID()].first, rotator[direction.getID()].second );
            default:
                return std::make_unique< HeadUnknownDirectionFunctor<float> >( &headSnapshot, rotator[direction.getID()].first, rotator[direction.getID()].second );
        }
    }

}
