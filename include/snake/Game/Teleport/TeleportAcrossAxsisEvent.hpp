#ifndef TELEPORTACROSSAXSISEVENT_H
#define TELEPORTACROSSAXSISEVENT_H

#include <snake/Eventer/Event.hpp>
#include <snake/Core/EntityComponentSystem/Entity.hpp>
#include <snake/Game/Teleport/TeleportAcrossAxisComponent.hpp>

namespace snake::game {    

    struct TeleportAcrossAxsisEvent : public eventer::Event<TeleportAcrossAxsisComponent> {
        core::Entity *const entityToTeleport;  
        core::Entity *const teleporter;  

        TeleportAcrossAxsisEvent(core::Entity *const entityToTeleport, core::Entity *const teleporter)
        : entityToTeleport(entityToTeleport)
        , teleporter(teleporter) {
        
        }

    };

}

#endif /* TELEPORTACROSSAXSISEVENT_H */
