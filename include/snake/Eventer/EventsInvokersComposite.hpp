#ifndef EVENTSINVOKERSCOMPOSITE_H
#define EVENTSINVOKERSCOMPOSITE_H

#include <snake/Eventer/EventInvoker.hpp>
#include <snake/Eventer/EventManager.hpp>
#include <memory>
#include <vector>

namespace snake::eventer {
    
    class EventsInvokersComposite {
    public:
        using EventReceiverUPtr = std::unique_ptr<BaseReceiver>;
    public:
        EventsInvokersComposite(EventManager* eventManager)
        : eventManager(eventManager) {

        }

        template<typename T, typename... Args>
        void add(Args... args) {
            auto receiver = std::make_unique< EventInvoker<T> >(std::forward<Args>(args)... );
            eventManager->subscribe<T>( receiver.get() );
            receivers.emplace_back( std::move(receiver) );
        }

    private:
        EventManager* eventManager;
        std::vector< std::unique_ptr<BaseReceiver> > receivers;
    };


}

#endif /* EVENTSINVOKERSCOMPOSITE_H */
