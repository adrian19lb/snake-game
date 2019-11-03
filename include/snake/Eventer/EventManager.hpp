#ifndef EVENTMENAGER_HPP_INCLUDED
#define EVENTMENAGER_HPP_INCLUDED

#include <vector>
#include <algorithm>
#include <snake/Eventer/Receiver.hpp>

namespace snake::eventer {

    class EventManager {
    public:
        using ReceiverArray = std::vector<BaseReceiver*>;
        using ImplSubscriberArray = std::vector<ReceiverArray>;
    public:
        template<typename EventType, typename ReceiverType> void subscribe(ReceiverType* receiver);
        template<typename EventType> void emit(EventType const& event);
        template<typename EventType, typename BaseReceiver> void unsubscribe(BaseReceiver* receiver);
    private:
        ImplSubscriberArray subscribers;
    };
}

#include <snake/Eventer/EventManager.inl>

#endif // EVENTMENAGER_HPP_INCLUDED
