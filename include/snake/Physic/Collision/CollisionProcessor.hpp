#ifndef COLLISIONPROCESSOR_H
#define COLLISIONPROCESSOR_H

#include <snake/Eventer/EventManager.hpp>
#include <snake/Core/EntityComponentSystem/Procesor.hpp>
#include <snake/Core/EntityComponentSystem/Entity.hpp>
#include <snake/Core/EntityComponentSystem/ComponentsManager.hpp>
#include <snake/Core/EntityComponentSystem/Visitable.hpp>
#include <snake/Core/EntityComponentSystem/ProcesorVisitor.hpp>
#include <snake/Physic/Collision/CollisionNotifier.hpp>
#include <snake/Physic/Body.hpp>
#include <map>

namespace snake::physic {

    class CollisionProcessor : public core::Procesor {
    public:
        using value_type = std::function<void(core::Entity *const)>;
    public:
        CollisionProcessor(eventer::EventManager* eventManager, core::ComponentsManager* componentsManager)
        : eventManager(eventManager)
        , componentsManager(componentsManager) {
        
        }

        template<typename CollisionNotifierType> void add(core::Entity *const entity) { 
            auto& collisonComponents = collisionNotifiers[entity->id];
            collisonComponents.emplace_back( std::make_unique<CollisionNotifierType>(entity, eventManager, componentsManager));
        }

        void enter(core::ProcesorVisitor* visitor) override { 
            visitor->visit(this);
        }
    protected:
        bool doesContainComponents(const core::Entity *const entity) const override { 
            return entity->has<physic::Body>();
        }

        void update(core::Entity *const entity, core::ComponentsManager* components) override { 
            for (auto&& entityCollisionNotifiers : collisionNotifiers) {
                for (auto&& collisionNotifier : entityCollisionNotifiers.second) {
                    collisionNotifier->notifyIfIsSpecificCollisionType(entity); 
                }
            }
        }  
    private:
        eventer::EventManager* eventManager;
        core::ComponentsManager* componentsManager;
        std::map<core::EntityID, std::vector<std::unique_ptr<CollisionNotifier>>> collisionNotifiers;
    };

}

#endif /* COLLISIONPROCESSOR_H */
