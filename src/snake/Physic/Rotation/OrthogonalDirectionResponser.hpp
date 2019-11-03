#ifndef ORTHOGONALDIRECTIONRESPONSER_H
#define ORTHOGONALDIRECTIONRESPONSER_H

#include <snake/Physic/Rotation/DirectionResponser.hpp>
#include <snake/Physic/PhysicComponent.hpp>

namespace snake::physic {
   
    class Direction;

    class OrthogonalDirectionResponser : public DirectionResponser {
    public:
        OrthogonalDirectionResponser(PhysicComponent* segment);
        std::unique_ptr<Direction> response() const override;
    private:
        std::unique_ptr<Direction> createDirectionIfPrevPhysicComponentExist() const;
        bool isHorizontalLayout(PhysicComponent const& current, physic::PhysicComponent const& previous) const;
        bool isVerticalLayout(PhysicComponent const& current, physic::PhysicComponent const& previous) const;
    private:
        PhysicComponent* segment; 
    };
}


#endif /* ORTHOGONALDIRECTIONRESPONSER_H */
