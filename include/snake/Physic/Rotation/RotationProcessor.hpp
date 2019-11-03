#ifndef ROTATIONPROCESSOR_H
#define ROTATIONPROCESSOR_H

#include <snake/Core/EntityComponentSystem/Procesor.hpp>
#include <snake/Core/EntityComponentSystem/ComponentsManager.hpp>
#include <snake/Physic/Rotation/BodyHeadRotator.hpp>
#include <map>

namespace snake::physic {
    
    class RotationProcessor : public core::Procesor {
    public:
        using BodyHeadRotatorUPtr = std::unique_ptr<BodyHeadRotator>;
        using value_type = std::function<BodyHeadRotatorUPtr(core::Entity *const) >;
    public:
        void enter(core::ProcesorVisitor* visitor) override;

        void add(core::EntityID id, BodyHeadRotatorUPtr moveBehaviour);
    protected:
        void update(core::Entity *const entity, core::ComponentsManager* components) override;
        
        bool doesContainComponents(const core::Entity *const entity) const override;
    private:
        std::map<core::EntityID, BodyHeadRotatorUPtr> rotators;
    };


}

#endif /* ROTATIONPROCESSOR_H */
