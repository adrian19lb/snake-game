#ifndef PROCESOR_H
#define PROCESOR_H

#include <snake/Core/EntityComponentSystem/EntityReceiver.hpp>
#include <snake/Core/EntityComponentSystem/Visitable.hpp>
#include <set>

namespace snake::core {
    
    struct Entity;
    
    using ProcesorID = unsigned int long;

    class Procesor  : public EntityReceiver, public Visitable {
    public:
        Procesor();
        ~Procesor() = default;
        void process();
        ProcesorID getID();
        void receive(Entity *const entity) override;
        void set(ComponentsManager* componentsManager) override;
        virtual void enter(ProcesorVisitor* visitor) override = 0;
    private:
        void updateEachEntityComponents();
    protected:
        virtual void update(Entity *const entity, ComponentsManager* componentsManager) = 0;
        virtual bool doesContainComponents(const Entity *const entity) const = 0;
    private:
        static ProcesorID currentID;
        ProcesorID id;
        std::set<Entity*> entities;
        ComponentsManager* componentsManager;
    };

}

#endif /* PROCESOR_H */
