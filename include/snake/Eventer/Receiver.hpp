#ifndef RECEIVER_HPP_INCLUDED
#define RECEIVER_HPP_INCLUDED

#include <snake/Eventer/BaseReceiver.hpp>

namespace snake::eventer {

    template<typename EventType>
    class Receiver : public BaseReceiver {
    public:
        virtual ~Receiver() = default;
        virtual void receive(EventType const& event) = 0;
    };

}
#endif // RECEIVER_HPP_INCLUDED
