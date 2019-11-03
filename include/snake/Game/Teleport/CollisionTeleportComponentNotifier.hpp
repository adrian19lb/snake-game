#ifndef COLLISIONTELEPORTCOMPONENTNOTIFIER_H
#define COLLISIONTELEPORTCOMPONENTNOTIFIER_H

#include <snake/Physic/Collision/SpecificCollisionTypeNotifier.hpp>
#include <snake/Game/Teleport/TeleportComponent.hpp>
#include <snake/Game/Teleport/TeleportAcrossAxsisEvent.hpp>

namespace snake::game {
    
    class CollisionTeleportComponentNotifier : public physic::SpecificCollisionTypeNotifier<TeleportAcrossAxsisComponent> {
    public:
        CollisionTeleportComponentNotifier(core::Entity *const entity, eventer::EventManager* eventManager, core::ComponentsManager* componentsManager)
        : SpecificCollisionTypeNotifier(entity, eventManager, componentsManager)
        , mComponentsManager(componentsManager) {
        
        }
    protected:
        std::unique_ptr<physic::BodyCollisionDetector> createBodyCollisionComponent(core::Entity *const entity) override {
            auto body = mComponentsManager->pull<physic::Body>(entity);
            
            return std::make_unique<physic::BodyCollisionDetector>(body); 
        }

        std::unique_ptr<eventer::Event<TeleportAcrossAxsisComponent>> createEvent(core::Entity *const entityToTeleport, core::Entity *const teleporter) override {
            return std::make_unique<TeleportAcrossAxsisEvent>(entityToTeleport, teleporter);
       }
    private:
        core::ComponentsManager* mComponentsManager;
    };
    

}


#endif /* COLLISIONTELEPORTCOMPONENTNOTIFIER_H */
