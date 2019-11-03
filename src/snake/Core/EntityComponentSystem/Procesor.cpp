#include <snake/Core/EntityComponentSystem/Procesor.hpp>
#include <snake/Core/EntityComponentSystem/Entity.hpp>

namespace snake::core {
    
    ProcesorID Procesor::currentID = 0ul;
        
    Procesor::Procesor()
    : id (currentID++) {
      
    }

    void Procesor::receive(Entity *const entity) {
        if ( doesContainComponents(entity) && entity->isAlive() ) {
            entities.emplace(entity);
        }else if (!doesContainComponents(entity) || !entity->isAlive() ){
            entities.erase(entity);
        }
    }
    
    //TODO: Detach processors when world was deleted and
    //clear handled entities list;
    void Procesor::process() {
        try {
            updateEachEntityComponents();
        }catch(std::out_of_range const& exceptation) {
        
       
        }
    }

    void Procesor::updateEachEntityComponents() {
        for (auto&& entity : entities) {
            update(entity, componentsManager);
        }
    }

    void Procesor::set(ComponentsManager* componentsManager) {
        this->componentsManager = componentsManager;
    }
    
    ProcesorID Procesor::getID() { 
        return id; 
    }



}
