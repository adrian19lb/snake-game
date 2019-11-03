namespace snake::game {
        
    template<typename T> typename T::value_type ProcessorsAttacher::get(ProcesorID id) {
        return logicComponentsFactory->create<typename T::value_type>(id);
    }
    
    template<typename ComponentType> ComponentType* ProcessorsAttacher::pull(const core::Entity* entity) {
        return componentsManager->pull<ComponentType>(entity);
    }
    
    template<typename Functor> void ProcessorsAttacher::add(ProcesorID id, Functor&& functor) {
        logicComponentsFactory->add( id, std::forward<Functor>(functor) ); 
    }

}
