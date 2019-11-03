#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <SFML/System/Vector2.hpp>
#include <snake/Core/EntityComponentSystem/Entity.hpp>
#include <snake/Core/EntityComponentSystem/ComponentsManager.hpp>

namespace snake::core {
    
    class EntityReceiver;
     
    class World {
    public:
        World(sf::Vector2f size);
        ~World();
    private:
        void notify(Entity *const entity);
    public:
        void registerReceiver(EntityReceiver* receiver);
        void erase(Entity* entity);
        ComponentsManager& getComponentsManager();
        sf::Vector2f const& getSize() const;
        sf::Vector2f const& getOrigin() const;
        template<typename... ComponentType> Entity* create(std::unique_ptr<ComponentType>... components);
        template<typename... ComponentType> void erase(Entity *const entity);
        template<typename... ComponentType> void attach(Entity *const entity, std::unique_ptr<ComponentType>... component);
        template<typename... ComponentType> void attach(Entity *const entity);
        template<typename... ComponentType> void detach(Entity *const entity);
    private:
        void notifyIfNotEmplaced(EntityReceiver* receiver);
        void notify(EntityReceiver* receiver);
        template<typename Functor, typename... ComponentType> void callFunctorWith(Entity *const entity, Functor&& functor);
        EntityID createID();
    private:
        std::vector< std::unique_ptr<Entity> > entities;
        sf::Vector2f size;
        sf::Vector2f origin;
        ComponentsManager componentsManager;
        std::vector<EntityReceiver*> entityReceivers;
    };
}

#include <snake/Core/EntityComponentSystem/World.inl>

#endif /* WORLD_H */
