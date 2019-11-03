#ifndef SYSTEM_H
#define SYSTEM_H

#include <vector>
#include <memory>
#include <snake/Core/EntityComponentSystem/Procesor.hpp>

namespace snake::core {

    class World;

}

namespace snake::game {

    class System {
    public:
        virtual ~System() = default;
        System(core::World* world);
   public:
        template<typename T> void enter(T* creator);

        virtual void process();
    protected:
        void add(std::unique_ptr<core::Procesor> processor);
        void registerProcesorsToWorld();
    private:
        core::World* world;
        std::vector<std::unique_ptr<core::Procesor> > processors;
    };

}

#include <snake/Game/System/System.tpp>

#endif /* SYSTEM_H */
