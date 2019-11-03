#ifndef PLAYERPROCESSORSATTACHER_H
#define PLAYERPROCESSORSATTACHER_H

#include <snake/Physic/Movement/MoveCommandProcessor.hpp>
#include <snake/Physic/Movement/MoveBehaviourProcessor.hpp>
#include <snake/Physic/Rotation/RotationProcessor.hpp>
#include <snake/Physic/Collision/CollisionProcessor.hpp>
#include <snake/Animator/TextureRectID.hpp>
#include <snake/Animator/TextureRectFactory.hpp>
#include <snake/Animator/AnimationProcessor.hpp>
#include <snake/Renderer/MeshProcessor.hpp>
#include <snake/Game/Entity/ProcessorsAttacher.hpp>

namespace snake::game {

    class PlayerProcessorsAttacher : public ProcessorsAttacher {
    public:
        PlayerProcessorsAttacher(core::ComponentsManager* manager, animator::TextureRectFactory<animator::TextureRect, int>* textFactory);
        virtual void visit(animator::AnimationProcessor* procesor) override;
    private:
        std::unique_ptr<animator::Animator> tryCreateAnimator(const core::Entity* entity);
    public:
        virtual void visit(renderer::MeshProcesor* procesor) override;
        virtual void visit(physic::MoveCommandProcessor* procesor) override;
        virtual void visit(physic::MoveBehaviourProcessor* procesor) override;
        virtual void visit(physic::RotationProcessor* procesor) override;
        virtual void visit(physic::CollisionProcessor* procesor) override;
    private:
        animator::TextureRectFactory<animator::TextureRect, int>* textFactory;
    };

}

#endif /* LOGICCOMPONENTAPPENDER_H */
