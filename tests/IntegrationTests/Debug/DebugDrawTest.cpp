#include <snake/Debug/DebugDraw.hpp>
#include <gtest/gtest.h>

namespace snake::testing {

    TEST(DebugDrawTest, testProcess) {
        debug::DebugDraw debugDraw;
        debugDraw.process(); 
    }


}
