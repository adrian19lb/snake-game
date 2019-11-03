namespace snake::eventer {
    
    template<typename EventType, typename ReceiverType> void EventManager::subscribe(ReceiverType* receiver) {
        if ( subscribers.size() <= EventType::getId() ) {
            subscribers.resize(EventType::getId() + 1);
        }

        auto& receivers = subscribers[ EventType::getId() ];
        if ( receivers.size() <= receiver->getId() ) {
            receivers.resize(receiver->getId() + 1);
        }

        receivers[ receiver->getId() ] = receiver;
    }

    template<typename EventType> void EventManager::emit(EventType const& event) {
        auto& receivers = subscribers.at( EventType::getId() );
        for (auto receiver : receivers) {
            if (receiver) {
                auto& castedReceiver = static_cast< Receiver<EventType>& >(*receiver);
                castedReceiver.receive(event);
            }
        }
    }
    
    template<typename EventType, typename ReceiverType> void EventManager::unsubscribe(ReceiverType* receiver) {
        auto& receivers = subscribers.at( EventType::getId() );
        receivers.erase(std::remove_if(receivers.begin(), receivers.end(),[&receiver](auto const& itr){
            return itr == receiver; 
        }), receivers.end());
    }
}
