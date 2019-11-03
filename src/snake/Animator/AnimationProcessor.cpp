#include <snake/Core/EntityComponentSystem/ProcesorVisitor.hpp>
#include <snake/Core/EntityComponentSystem/ComponentsManager.hpp>
#include <snake/Animator/AnimationProcessor.hpp>
#include <snake/Animator/AnimationComponent.hpp>
#include <snake/Renderer/RenderComponents.hpp>

namespace snake::animator {
    
    void AnimationProcessor::enter(core::ProcesorVisitor* visitor) {
        visitor->visit(this);
    }

    void AnimationProcessor::update(core::Entity *const entity, core::ComponentsManager* components) {
        auto animationComponent = components->pull<AnimationComponent>(entity);
        auto& animator = animators.at(entity->id);
        animator->animate();
        auto const& newAnimation = animator->getAnimation();
        animationComponent->animation = &newAnimation;
    }

    bool AnimationProcessor::doesContainComponents(const core::Entity *const entity) const {
        return entity->has<physic::Body, renderer::RenderComponents, AnimationComponent>();
    }

}
