#ifndef EVENTINVOKER_H
#define EVENTINVOKER_H

#include <snake/Eventer/Receiver.hpp>
#include <functional>
#include <iostream>

namespace snake::eventer {
    
    template<typename EventType >
    class EventInvoker : public Receiver<EventType> {
        using Invoker = std::function< void(EventType&) >;
    public:
        EventInvoker(Invoker&& func)
        : invoker(func) {
        
        }

    public:
        void receive(EventType const& event) override {
            try {
                invoker(event);
            }catch(std::bad_function_call const& exception) {
                std::cerr << exception.what() << std::endl; 
            }
        }
    private:
        Invoker invoker;
    };

}


#endif /* EVENTINVOKER_H */
