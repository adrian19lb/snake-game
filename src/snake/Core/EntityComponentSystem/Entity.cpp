#include <snake/Core/EntityComponentSystem/Entity.hpp>

namespace snake::core {
    
    Entity::Entity(const EntityID id)
    : id(id) {
        
    }

    bool Entity::isAlive() const {
        return mIsAlive;
    }


}
