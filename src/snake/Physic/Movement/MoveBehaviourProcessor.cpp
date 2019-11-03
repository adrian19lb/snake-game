#include <snake/Core/EntityComponentSystem/ProcesorVisitor.hpp>
#include <snake/Core/EntityComponentSystem/ComponentsManager.hpp>
#include <snake/Physic/Movement/MoveBehaviourProcessor.hpp>
#include <snake/Physic/Movement/DeviceMoveCommandListener.hpp>

namespace snake::physic {
    
    MoveBehaviourProcessor::MoveBehaviourProcessor(float dt)
    : dt(dt) {
    
    }

    void MoveBehaviourProcessor::enter(core::ProcesorVisitor* visitor) {
        visitor->visit(this);
    }

    void MoveBehaviourProcessor::add(core::EntityID id, MoveBehaviourUPtr moveBehaviour) {
        moveBehaviours.emplace( std::make_pair(id, std::move(moveBehaviour)) );
    }
        
    void MoveBehaviourProcessor::update(core::Entity *const entity, core::ComponentsManager* components) {
        auto inputComponent = components->pull<ConstantMovementComponent>(entity);
        auto& moveBehaviour = moveBehaviours.at(entity->id);
                
        inputComponent->movement->execute(moveBehaviour.get(), dt);
    }

    bool MoveBehaviourProcessor::doesContainComponents(const core::Entity *const entity) const {
        return entity->has<physic::Body, ConstantMovementComponent>();
    }

}
