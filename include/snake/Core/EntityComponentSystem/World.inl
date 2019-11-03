#include <algorithm>

namespace snake::core {
        
    template<typename... ComponentType> Entity* World::create(std::unique_ptr<ComponentType>... component) {
        entities.emplace_back(std::make_unique<enable_make<Entity>>(createID()));
        World::attach( entities.back().get(), std::move(component)... );
        
        return entities.back().get();
    }
        
    template<typename... ComponentType> void World::detach(Entity *const entity) {
        callFunctorWith( entity, [entity]() { entity->detach<ComponentType...>(); } );   
        notify(entity);
    }

    template<typename... ComponentType> void World::erase(Entity *const entity) {
        componentsManager.detach<ComponentType... >(entity);
        World::detach<ComponentType...>(entity);
    }

    template<typename... ComponentType> void World::attach(Entity *const entity, std::unique_ptr<ComponentType>... component) {
        World::attach<ComponentType...>(entity);
        componentsManager.attach( entity, std::move(component)... );
    }
    
    template<typename... ComponentType> void World::attach(Entity *const entity) {
        callFunctorWith( entity, [entity]() { entity->attach<ComponentType...>(); } );   
        notify(entity);
    }

    template<typename Functor, typename... ComponentType> void World::callFunctorWith(Entity *const entity, Functor&& functor) {
        auto found = std::find_if(entities.begin(), entities.end(), [entity](auto& itr) {
            return itr->id == entity->id;      
        });

        if ( found != entities.end() ) {
            functor();    
        }
    
    }
        

}
