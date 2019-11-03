#ifndef MOVECOMMANDPROCESSOR_H
#define MOVECOMMANDPROCESSOR_H

#include <snake/Core/EntityComponentSystem/Procesor.hpp>
#include <snake/Core/EntityComponentSystem/Visitable.hpp>
#include <snake/Core/EntityComponentSystem/ComponentsManager.hpp>
#include <snake/Physic/Movement/ConstantMovementComponent.hpp>
#include <snake/Physic/Movement/DeviceMoveCommandListener.hpp>
#include <map>

namespace snake::physic {
    
    class MoveCommandProcessor : public core::Procesor {
    public:
        using DeviceMoveCommandListenerUPtr = std::unique_ptr<DeviceMoveCommandListener>;
        using value_type = std::function<DeviceMoveCommandListenerUPtr() >;
    public:
        MoveCommandProcessor() = default;

        void enter(core::ProcesorVisitor* visitor) override;

        void add(core::EntityID id, DeviceMoveCommandListenerUPtr commandListener);
    protected:
        void update(core::Entity *const entity, core::ComponentsManager* components) override;
        
        bool doesContainComponents(const core::Entity *const entity) const override;
    private:
        std::map<core::EntityID, DeviceMoveCommandListenerUPtr> deviceCommandListeners;
    };

}

#endif /* MOVECOMMANDPROCESSOR_H */
