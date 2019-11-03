#include <snake/Physic/BodyExtender/NearTailBodyExtender.hpp>
#include <snake/Physic/BodyExtender/DownSideOffsetCreator.hpp>
#include <snake/Physic/BodyExtender/UpSideOffsetCreator.hpp>
#include <snake/Physic/BodyExtender/RightSideOffsetCreator.hpp>
#include <snake/Physic/BodyExtender/LeftSideOffsetCreator.hpp>
#include <gtest/gtest.h>

namespace snake::physic::testing {
    
    class NearTailBodyExtenderTest : public ::testing::Test {
    public:
        NearTailBodyExtenderTest()
        : body( sf::Vector2f(0.f, 0.f), sf::Vector2f(1.f, 1.f) )
        , bodyExtender(&body) {
        
        }

        Body body;
        NearTailBodyExtender bodyExtender;
    };
    
    TEST_F(NearTailBodyExtenderTest, testExtendAtUp) {
        bodyExtender.extendFrom( UpSideOffsetCreator( &body.tail() ));

        EXPECT_EQ(body.tail().position.y, 1.f);
        EXPECT_THROW( bodyExtender.extendFrom(DownSideOffsetCreator( &body.tail() )), std::logic_error); 
    }

    TEST_F(NearTailBodyExtenderTest, testExtendAtDown) {
        bodyExtender.extendFrom( DownSideOffsetCreator( &body.tail() ));
        
        EXPECT_EQ(body.tail().position.y, -1.f);
        EXPECT_THROW( bodyExtender.extendFrom(UpSideOffsetCreator( &body.tail() )), std::logic_error); 
    }
    
    TEST_F(NearTailBodyExtenderTest, testExtendAtRight) {
        bodyExtender.extendFrom( RightSideOffsetCreator( &body.tail() ));
        
        EXPECT_EQ(body.tail().position.x, 1.f);
        EXPECT_THROW( bodyExtender.extendFrom(LeftSideOffsetCreator( &body.tail() )), std::logic_error); 
    }
    
    TEST_F(NearTailBodyExtenderTest, testExtendAtLeft) {
        bodyExtender.extendFrom( LeftSideOffsetCreator( &body.tail() ));
        
        EXPECT_EQ(body.tail().position.x, -1.f);
        EXPECT_THROW( bodyExtender.extendFrom(RightSideOffsetCreator( &body.tail() )), std::logic_error); 
    }

}
