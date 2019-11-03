#ifndef PROCESSORSATTACHER_H
#define PROCESSORSATTACHER_H

#include <snake/Core/EntityComponentSystem/ProcesorVisitor.hpp>
#include <snake/Core/EntityComponentSystem/ComponentsManager.hpp>
#include <snake/Core/AnyObjectFactory.hpp>
#include <memory>

namespace snake::game {
    
    struct Entity;

    class ProcessorsAttacher : public core::ProcesorVisitor {
        using ProcesorID = unsigned int long;
    public:
        ProcessorsAttacher(core::ComponentsManager* componentsManager);

        virtual void visit(animator::AnimationProcessor* procesor) override = 0; 

        virtual void visit(renderer::MeshProcesor* procesor) override = 0; 

        virtual void visit(physic::MoveCommandProcessor* procesor) override = 0; 

        virtual void visit(physic::MoveBehaviourProcessor* procesor) override = 0; 

        virtual void visit(physic::RotationProcessor* procesor) override = 0; 

        virtual void visit(physic::CollisionProcessor* procesor) override = 0; 

        template<typename T> typename T::value_type get(ProcesorID id);
    protected:
        template<typename ComponentType> ComponentType* pull(const core::Entity* entity);

        template<typename Functor> void add(ProcesorID id, Functor&& functor);
    private:
        std::unique_ptr< core::AnyObjectFactory<ProcesorID> > logicComponentsFactory;
        core::ComponentsManager* componentsManager;
    };

}

#include <snake/Game/Entity/ProcessorsAttacher.inl>

#endif /* PROCESSORSATTACHER_H */
