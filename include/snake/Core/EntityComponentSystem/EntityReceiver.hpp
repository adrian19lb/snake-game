#ifndef ENTITYRECEIVER_H
#define ENTITYRECEIVER_H

#include <cstddef>

namespace snake::core {
    
    struct Entity;

    class ComponentsManager; 

    class EntityReceiver {
    public:
        virtual ~EntityReceiver() = default;
        virtual void receive(Entity *const entity) = 0;
        virtual void set(ComponentsManager* componentsManager) = 0;
    };

}

#endif /* ENTITYRECEIVER_H */
