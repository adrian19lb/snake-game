#include <snake/Game/System/System.hpp>
#include <snake/Core/EntityComponentSystem/World.hpp>

namespace snake::game {
    
    System::System(core::World* world)
    : world(world) {
        
    }

    void System::registerProcesorsToWorld() {
        for(auto&& processor : processors) {
            world->registerReceiver(processor.get()); 
        }
    }

    void System::process() {
        for (auto&& processor : processors) {
            processor->process();
        }
    }

    void System::add(std::unique_ptr<core::Procesor> processor) {
        processors.emplace_back(std::move(processor));
    }


}
