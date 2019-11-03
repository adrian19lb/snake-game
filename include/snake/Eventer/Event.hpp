#ifndef EVENT_HPP_INCLUDED
#define EVENT_HPP_INCLUDED

#include <snake/Eventer/BaseEvent.hpp>

namespace snake::eventer {
    
    template<typename EventType>
    class Event : public BaseEvent {
    public:
        static unsigned getId() { return id; }
    protected:
        static unsigned id;
    };

    template<typename EventType>
    unsigned Event<EventType>::id = BaseEvent::baseId++;
}

#endif // EVENT_HPP_INCLUDED
