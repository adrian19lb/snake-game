#include <snake/Core/EntityComponentSystem/ComponentsManager.hpp>
#include <snake/Core/EntityComponentSystem/ProcesorVisitor.hpp>
#include <snake/Physic/Movement/MoveCommandProcessor.hpp>
#include <snake/Physic/Movement/DeviceMoveCommandListener.hpp>

namespace snake::physic {
    
    void MoveCommandProcessor::enter(core::ProcesorVisitor* visitor) {
        visitor->visit(this);
    }

    void MoveCommandProcessor::add(core::EntityID id, DeviceMoveCommandListenerUPtr commandListener) {
        deviceCommandListeners.emplace( std::make_pair(id, std::move(commandListener)) );
    }
        
    void MoveCommandProcessor::update(core::Entity *const entity, core::ComponentsManager* components) {
        auto inputComponent = components->pull<ConstantMovementComponent>(entity);
        auto& commandListener = deviceCommandListeners.at(entity->id);
        auto command = commandListener->listen();
                
        inputComponent->movement = command; 
    }

    bool MoveCommandProcessor::doesContainComponents(const core::Entity *const entity) const {
        return entity->has<ConstantMovementComponent>();
    }

}
