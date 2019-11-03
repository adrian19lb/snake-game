#ifndef DEFAULTCOMPONENTSCREATOR_H
#define DEFAULTCOMPONENTSCREATOR_H

#include <snake/Core/EntityComponentSystem/World.hpp>

namespace snake::core {

    class DefaultComponentsCreator {
    public:
        DefaultComponentsCreator(World* world)
        : world(world) {
        
        }
        
        template<typename... ComponentType>
        Entity* create() {
            auto componentsTuple = std::make_tuple( std::make_unique<ComponentType>()... );
            auto entity = world->create();
            std::apply([this, &entity](auto&... itr) {
                world->attach(entity, std::move(itr)... );
            }, componentsTuple);

            return entity;
        }
        
    private:
        World* world;
    };

}

#endif /* DEFAULTCOMPONENTSCREATOR_H */
