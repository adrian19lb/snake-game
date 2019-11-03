#ifndef MOCKRECEIVER_H
#define MOCKRECEIVER_H

#include <gmock/gmock.h>
#include <snake/Eventer/Receiver.hpp>

namespace snake::eventer::testing {
    
    template<typename T>
    class MockReceiver : public Receiver<T> {
    public:
        MOCK_METHOD(void, receive, (T const&), (override)); 
    };

}

#endif /* MOCKRECEIVER_H */



