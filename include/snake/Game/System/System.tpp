namespace snake::game {

    template<typename T> void System::enter(T* creator) {
        for(auto&& processor : processors) {
            creator->add(processor.get()); 
        }
    }

}
