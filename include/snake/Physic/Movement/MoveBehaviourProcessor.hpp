#ifndef MOVEBEHAVIOURPROCESSOR_H
#define MOVEBEHAVIOURPROCESSOR_H

#include <map>
#include <snake/Core/EntityComponentSystem/Procesor.hpp>
#include <snake/Core/EntityComponentSystem/ComponentsManager.hpp>
#include <snake/Physic/Body.hpp>
#include <snake/Physic/Movement/ConstantMovementComponent.hpp>
#include <snake/Physic/Movement/MoveBehaviour.hpp>

namespace snake::physic {

    class MoveBehaviourProcessor : public core::Procesor {
    public:
        using MoveBehaviourUPtr = std::unique_ptr<MoveBehaviour>;
        using value_type = std::function<MoveBehaviourUPtr(core::Entity *const) >;
    public:
        MoveBehaviourProcessor(float dt);

        void enter(core::ProcesorVisitor* visitor) override;

        void add(core::EntityID id, MoveBehaviourUPtr moveBehaviour);
    protected:
        void update(core::Entity *const entity, core::ComponentsManager* components) override;
        
        bool doesContainComponents(const core::Entity *const entity) const override;
    private:
        std::map<core::EntityID, MoveBehaviourUPtr> moveBehaviours;
        float dt;
    };

}

#endif /* MOVEBEHAVIOURPROCESSOR_H */
