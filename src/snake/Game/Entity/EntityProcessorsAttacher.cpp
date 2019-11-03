#include <snake/Physic/Movement/MoveCommandProcessor.hpp>
#include <snake/Physic/Movement/MoveBehaviourProcessor.hpp>
#include <snake/Physic/Rotation/RotationProcessor.hpp>
#include <snake/Physic/Collision/CollisionProcessor.hpp>
#include <snake/Animator/AnimationProcessor.hpp>
#include <snake/Renderer/MeshProcessor.hpp>
#include <snake/Game/Entity/EntityProcessorsAttacher.hpp>

namespace snake::game {

    EntityProcessorsAttacher::EntityProcessorsAttacher(core::Entity *const entity, std::unique_ptr<ProcessorsAttacher> logicComponents)
    : entity(entity)
    , logicComponents( std::move(logicComponents) ) {
    
    }
        
    void EntityProcessorsAttacher::visit(animator::AnimationProcessor* processor) {
        logicComponents->visit(processor);
        auto animatorCreator = logicComponents->get<animator::AnimationProcessor>(processor->getID());
        processor->add(entity->id, animatorCreator(entity));
    }

    void EntityProcessorsAttacher::visit(renderer::MeshProcesor* processor) {
        logicComponents->visit(processor);
        auto modelFactory = logicComponents->get<renderer::MeshProcesor>(processor->getID());
        processor->add(entity->id, modelFactory);
    }

    void EntityProcessorsAttacher::visit(physic::MoveCommandProcessor* processor) {
        logicComponents->visit(processor);
        auto moveCommandListenerFactory = logicComponents->get<physic::MoveCommandProcessor>(processor->getID());
        processor->add(entity->id, moveCommandListenerFactory());
    
    }
    
    void EntityProcessorsAttacher::visit(physic::MoveBehaviourProcessor* processor) {
        logicComponents->visit(processor);
        auto moveBehaviourFactory = logicComponents->get<physic::MoveBehaviourProcessor>(processor->getID());
        processor->add(entity->id, moveBehaviourFactory(entity));
    
    }
    
    void EntityProcessorsAttacher::visit(physic::RotationProcessor* processor) {
        logicComponents->visit(processor);
        auto rotatorFactory = logicComponents->get<physic::RotationProcessor>(processor->getID());
        processor->add(entity->id, rotatorFactory(entity));
    }
    
    void EntityProcessorsAttacher::visit(physic::CollisionProcessor* processor) {
        logicComponents->visit(processor);
        auto collisionAttacherFactory = logicComponents->get<physic::CollisionProcessor>(processor->getID());
        collisionAttacherFactory(entity);
    }

        
}
