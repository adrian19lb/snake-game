#ifndef BODYDETACHEDHEADROTATOR_H
#define BODYDETACHEDHEADROTATOR_H

#include <snake/Physic/Rotation/BodyHeadRotator.hpp>
#include <snake/Physic/Rotation/UnknownDirection.hpp>

namespace snake::physic {

    class BodyDetachedHeadRotator : public BodyHeadRotator {
    public:
        BodyDetachedHeadRotator(Body* body);
    protected:
        std::unique_ptr< core::IfElseConditionFunctor<float> > createHeadDirectionState(Direction const& direction) override;
    private:
        bool isHeadDetachedAcrossAxis() const;
        bool isHeadNotDetachedAcrossX() const;
        bool isHeadNotDetachedAcrossY() const;
    private:
        UnknownDirection unknownDirection;
    };

}

#endif /* BODYDETACHEDEADROTATOR_H */
