#ifndef DUMMYEVENT_H
#define DUMMYEVENT_H

#include <snake/Eventer/Event.hpp>

namespace snake::eventer::testing {

    struct DummyEvent : public Event<DummyEvent> {
    
    };

}


#endif /* DUMMYEVENT_H */
