#ifndef ENTITYABSTRACTCREATOR_H
#define ENTITYABSTRACTCREATOR_H

#include <snake/Core/EntityComponentSystem/Entity.hpp>

namespace snake::game {
    
    enum class Side {
        North,
        South,
        West,
        East
    };
    
    class EntityAbstractCreator {
    public:
        virtual core::Entity* createPlayer() = 0;
        virtual core::Entity* createApple() = 0;
        virtual core::Entity* createMap() = 0;
        virtual core::Entity* createWall(Side id) = 0;
    };

}

#endif /* ENTITYABSTRACTCREATOR_H */
