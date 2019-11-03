#ifndef ANIMATIONPROCESSOR_H
#define ANIMATIONPROCESSOR_H

#include <map>
#include <snake/Core/EntityComponentSystem/Procesor.hpp>
#include <snake/Core/EntityComponentSystem/Entity.hpp>
#include <snake/Physic/Body.hpp>
#include <snake/Animator/Animator.hpp>

namespace snake::animator {
    
    class AnimationProcessor : public core::Procesor {
    public:
        using AnimatorUPtr = std::unique_ptr<Animator>;
        using value_type = std::function<AnimatorUPtr(core::Entity *const) >;
    public:
        AnimationProcessor() = default;

        void enter(core::ProcesorVisitor* visitor) override;

        void add(core::EntityID id, AnimatorUPtr animator) {
            animators.emplace( std::make_pair(id, std::move(animator)) );
        }
    protected:
        void update(core::Entity *const entity, core::ComponentsManager* components) override;

        bool doesContainComponents(const core::Entity *const entity) const override;
    private:
        std::map< core::EntityID, AnimatorUPtr > animators;
    };

}

#endif /* ANIMATIONPROCESSOR_H */
