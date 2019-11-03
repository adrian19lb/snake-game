#include <gtest/gtest.h>
#include <snake/Eventer/EventManager.hpp>
#include "MockReceiver.hpp"
#include "DummyEvent.hpp"

namespace snake::eventer::testing {
    
    class EventManagerTest : public ::testing::Test {
    public:
        EventManager eventManager;
        MockReceiver<DummyEvent> mockReceiver; 
        DummyEvent dummyEvent;
    };
    
    TEST_F(EventManagerTest, testEmitEventWhenSubcriberExist) {
        eventManager.subscribe<DummyEvent>(&mockReceiver);
        
        EXPECT_CALL(mockReceiver, receive(::testing::Ref(dummyEvent)))
            .Times(1);

        eventManager.emit(dummyEvent);
    }
    
    TEST_F(EventManagerTest, testEmitEventWhenSubcriberNotExist) {
        eventManager.subscribe<DummyEvent>(&mockReceiver);
        eventManager.unsubscribe<DummyEvent>(&mockReceiver);
        
        EXPECT_CALL(mockReceiver, receive(::testing::Ref(dummyEvent)))
            .Times(0);

        eventManager.emit(dummyEvent);
    }



}

