#include <SFML/System/Vector2.hpp>
#include <snake/Core/EntityComponentSystem/World.hpp>
#include <snake/Core/EntityComponentSystem/EntityReceiver.hpp>

namespace snake::core {
   
    World::World(sf::Vector2f size)
    : size(size)
    , origin(0.f, 0.f) {
    
    }

    World::~World() {
        componentsManager.clear();
    }
    
    void World::notify(Entity *const entity) {
        for (auto&& receiver : entityReceivers) {
            receiver->receive(entity); 
        }
    }
    
    void World::registerReceiver(EntityReceiver* receiver) {
        notifyIfNotEmplaced(receiver);
        receiver->set(&componentsManager);
        entityReceivers.emplace_back(receiver);
    }

    void World::notifyIfNotEmplaced(EntityReceiver* receiver) {
        if ( std::find(entityReceivers.begin(), entityReceivers.end(), receiver) == entityReceivers.end()) {
            notify(receiver);
        }
    
    }

    sf::Vector2f const& World::getOrigin() const {
        return origin;
    }
        
    ComponentsManager& World::getComponentsManager()  {
        return componentsManager;
    }
        
    sf::Vector2f const& World::getSize() const {
        return size;
    }

    void World::notify(EntityReceiver* receiver) {
        for (auto&& entity : entities) {
            receiver->receive(entity.get());
        }
    }
        
    void World::erase(Entity* entity) {
        entity->mIsAlive = false;
        notify(entity);
        auto id = entity->id;
        entities.erase( std::remove_if( entities.begin(), entities.end(), [id](auto& itr){
            return itr->id == id;      
        } ), entities.end());
        componentsManager.detach(entity);
    }
    
    EntityID World::createID() {
        static EntityID id = 0;
        EntityID nextID = id++;

        return nextID;
    }

}
