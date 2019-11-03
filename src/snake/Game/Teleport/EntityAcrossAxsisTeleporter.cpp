#include <snake/Game/Teleport/EntityAcrossAxsisTeleporter.hpp>

namespace snake::game {
        
    EntityAcrossAxsisTeleporter::EntityAcrossAxsisTeleporter(eventer::EventManager* eventManager, core::World* world)
    : componentsManager(&world->getComponentsManager()) {
        eventManager->subscribe<TeleportAcrossAxsisEvent>(this); 
    }

    void EntityAcrossAxsisTeleporter::receive(TeleportAcrossAxsisEvent const& event) {
        if (auto entity = event.entityToTeleport; entity->has<physic::Body>() && event.teleporter->has<TeleportAcrossAxsisComponent>()) {
            auto entityToTeleportBody = componentsManager->pull<physic::Body>(entity);
            auto teleportComponent = componentsManager->pull<TeleportAcrossAxsisComponent>(event.teleporter);
            entityToTeleportBody->head().position = teleportComponent->axis->transform(entityToTeleportBody->head().position);
        } 
    }
}
