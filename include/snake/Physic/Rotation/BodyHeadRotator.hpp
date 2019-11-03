#ifndef BODYHEADROTATOR_H
#define BODYHEADROTATOR_H

#include <snake/Physic/Body.hpp>
#include <memory>
#include <functional>
#include <vector>

namespace snake::core {
    template<typename T> class IfElseConditionFunctor;
}

namespace snake::physic {
    
    class Direction;

    class BodyHeadRotator {
        using DirectionConditionFunctors = std::pair< std::function<float()>, std::function<float()> >;
    public:
        BodyHeadRotator(Body* body);
        virtual ~BodyHeadRotator() = default;
    private:
        void setBodyHeadAsPreviousPhysicComponentForHeadSnapshot();
        void registerRotationAngles();
    public:
        float getAngle();
    private:
        void createHeadSnapshot();
        float getAngleDependsOfDirection();
    protected:
        PhysicComponent const& getHeadSnapshot() const;
        virtual std::unique_ptr< core::IfElseConditionFunctor<float> > createHeadDirectionState(Direction const& direction);
    private:
        Body* body;
        PhysicComponent headSnapshot;
        const int DIRECTION_CONDITION_AMOUNT;
        std::vector<DirectionConditionFunctors> rotator;
    };

}

#endif /* BODYHEADROTATOR_H */
