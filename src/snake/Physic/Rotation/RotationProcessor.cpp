#include <snake/Core/EntityComponentSystem/ProcesorVisitor.hpp>
#include <snake/Physic/Rotation/RotationProcessor.hpp>
#include <snake/Physic/Movement/ConstantMovementComponent.hpp>

namespace snake::physic {
    
    void RotationProcessor::enter(core::ProcesorVisitor* visitor) {
        visitor->visit(this);
    }

    void RotationProcessor::add(core::EntityID id, BodyHeadRotatorUPtr rotator) {
        rotators.emplace( std::make_pair(id, std::move(rotator)) );
    }
        
    void RotationProcessor::update(core::Entity *const entity, core::ComponentsManager* components) {
        auto body = components->pull<physic::Body>(entity);
        auto& rotator = rotators.at(entity->id);
        body->head().angle = rotator->getAngle();
        if (body->tail().next) {
            body->tail().angle = body->tail().next->angle;
        }
    }

    bool RotationProcessor::doesContainComponents(const core::Entity *const entity) const {
        return entity->has<physic::Body, ConstantMovementComponent>();
    }

}
