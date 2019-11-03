#ifndef COMPONENTSMANAGER_H
#define COMPONENTSMANAGER_H

#include <snake/Core/EntityComponentSystem/Component.hpp>
#include <snake/Core/EntityComponentSystem/Entity.hpp>
#include <unordered_map>
#include <array>
#include <memory>

namespace snake::core {
    
    class ComponentsManager {
        using ComponentUPtr = std::unique_ptr<BaseComponent>;
        using ComponentsArray = std::array< ComponentUPtr, 64>;
    public:
        template<typename... ComponentType> void attach(Entity const* entity, std::unique_ptr<ComponentType>... component) {
            (( components[entity->id].at( ComponentType::getID() ) = std::move(component) ), ... );        
        }
        
        template<typename... ComponentType> void detach(Entity const* entity) {
            (( components[entity->id].at( ComponentType::getID() ).reset()  ), ... );        
        }

        template<typename ComponentType> ComponentType* pull(Entity const* entity) {
            auto& entityComponentsArray = components.at(entity->id);
            auto& component = entityComponentsArray.at( ComponentType::getID() );
            
            return static_cast<ComponentType*>( component.get() );
        }

        void clear() {
            components.clear();
        }

    private:
        std::unordered_map<EntityID, ComponentsArray> components;
    };

}


#endif /* COMPONENTSMANAGER_H */
