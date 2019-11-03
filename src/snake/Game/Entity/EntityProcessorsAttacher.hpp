#ifndef ENTITYRESOURCESATTACHER_H
#define ENTITYRESOURCESATTACHER_H

#include <snake/Core/EntityComponentSystem/Entity.hpp>
#include <snake/Core/EntityComponentSystem/ProcesorVisitor.hpp>
#include <snake/Game/Entity/ProcessorsAttacher.hpp>
#include <snake/Animator/TextureRectFactory.hpp>

namespace snake::game {
    
    class EntityProcessorsAttacher : public core::ProcesorVisitor {
    public:
        EntityProcessorsAttacher(core::Entity *const entity, std::unique_ptr<ProcessorsAttacher> logicComponents);
        void visit(animator::AnimationProcessor* processor) override;
        void visit(renderer::MeshProcesor* processor) override;
        void visit(physic::MoveCommandProcessor* processor) override;
        void visit(physic::MoveBehaviourProcessor* processor) override;
        void visit(physic::RotationProcessor* processor) override;
        void visit(physic::CollisionProcessor* processor) override;
    private:
        core::Entity *const entity;
        std::unique_ptr<ProcessorsAttacher> logicComponents;

    };

}

#endif /* ENTITYRESOURCESATTACHER_H */
