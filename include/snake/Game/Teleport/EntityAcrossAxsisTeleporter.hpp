#ifndef ENTITYACROSSAXSISTELEPORTER_H
#define ENTITYACROSSAXSISTELEPORTER_H

#include <snake/Eventer/Receiver.hpp>
#include <snake/Eventer/EventManager.hpp>
#include <snake/Physic/Body.hpp>
#include <snake/Core/EntityComponentSystem/World.hpp>
#include <snake/Game/Teleport/TeleportAcrossAxsisEvent.hpp>

namespace snake::game {
    
    class EntityAcrossAxsisTeleporter : public eventer::Receiver<TeleportAcrossAxsisEvent> {
    public:
        EntityAcrossAxsisTeleporter(eventer::EventManager* eventManager, core::World* world);

        void receive(TeleportAcrossAxsisEvent const& event);
    private:
        core::ComponentsManager* componentsManager;
    };

}


#endif /* ENTITYACROSSAXSISTELEPORTER_H */
