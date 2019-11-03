#ifndef ENTITYCREATOR_H
#define ENTITYCREATOR_H

#include <snake/Core/EntityComponentSystem/World.hpp>
#include <snake/Core/EntityComponentSystem/ProcesorVisitor.hpp>
#include <snake/Core/EntityComponentSystem/Visitable.hpp>
#include <snake/Core/detail/DefaultComponentsCreator.hpp>

namespace snake::core {
    
    template<typename... ComponentType> 
    class EntityCreator {
    public:
        EntityCreator(World* world)
        : world(world) {

        }

        void add(core::Visitable* visitableProcesor) {
            procesorsToVisit.emplace(visitableProcesor); 
        }

        void remove(core::Visitable* visitableProcesor) {
            procesorsToVisit.erase(visitableProcesor); 
        }
        
        template<typename ProcesorVisitorType, typename... Args>  core::Entity* create(Args&&... args) {
            core::DefaultComponentsCreator defaultComponentsCreator(world);
            auto entity = defaultComponentsCreator.template create<ComponentType... >();
            auto procesorsVisitor = std::make_unique<ProcesorVisitorType>(entity, std::forward<Args>(args)... );
            visitEachVisitable( procesorsVisitor.get() );

            return entity;
        }
        
    private:
        void visitEachVisitable(ProcesorVisitor* visitor) {
            for (auto&& procesor : procesorsToVisit) {
                procesor->enter(visitor);            
            }
        }
    private:
        World* world;
        std::set<core::Visitable*> procesorsToVisit;
    };
}

#endif /* ENTITYCREATOR_H */
