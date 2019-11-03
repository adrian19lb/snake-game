#include <snake/Game/Entity/ProcessorsAttacher.hpp>
#include <snake/Core/AnyObjectFactory.hpp>

namespace snake::game {
        
    ProcessorsAttacher::ProcessorsAttacher(core::ComponentsManager* componentsManager)
    : logicComponentsFactory( std::make_unique<core::AnyObjectFactory<ProcesorID> >() )
    , componentsManager(componentsManager) {
        
    }

}
