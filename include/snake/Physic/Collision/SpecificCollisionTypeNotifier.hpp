#ifndef COLLISIONCOMPONENTNOTIFIER_H
#define COLLISIONCOMPONENTNOTIFIER_H

#include <snake/Physic/Collision/CollisionNotifier.hpp>
#include <snake/Physic/Collision/BodyCollisionDetector.hpp>
#include <snake/Core/EntityComponentSystem/ComponentsManager.hpp>
#include <snake/Eventer/EventManager.hpp>
#include <snake/Eventer/Event.hpp>

namespace snake::physic {
    
    template<typename T>
    class SpecificCollisionTypeNotifier : public CollisionNotifier {
    public:
        SpecificCollisionTypeNotifier(core::Entity *const entity, eventer::EventManager* eventManager, core::ComponentsManager* componentsManager)
        : eventManager(eventManager)
        , componentsManager(componentsManager)
        , entity(entity) {
        
        }    
        
        void notifyIfIsSpecificCollisionType(core::Entity *const entityWithSpecificComponent) override {
           auto bodyCollisionComponent = createBodyCollisionComponent(entity);
           auto checkingEntityBody = componentsManager->pull<Body>(entityWithSpecificComponent);
           if(bodyCollisionComponent->isAnyPhysicComponentOverlapedIn(checkingEntityBody) && entityWithSpecificComponent->has<T>()) {
               eventManager->emit(*createEvent(entity, entityWithSpecificComponent));
           }
       }

    protected:
        virtual std::unique_ptr<BodyCollisionDetector> createBodyCollisionComponent(core::Entity *const  entity) = 0;
        virtual std::unique_ptr<eventer::Event<T>> createEvent(core::Entity *const entity, core::Entity *const entityWithSpecificComponent) = 0;
    private:
        eventer::EventManager* eventManager;
        core::ComponentsManager* componentsManager;
        core::Entity *const entity;
    };

}



#endif /* COLLISIONCOMPONENTNOTIFIER_H */
