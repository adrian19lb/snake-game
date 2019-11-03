#include <gtest/gtest.h>
#include <snake/Physic/BodyExtender/NearHeadBodyExtender.hpp>
#include <snake/Physic/BodyExtender/UpSideOffsetCreator.hpp>
#include <snake/Physic/BodyExtender/DownSideOffsetCreator.hpp>
#include <snake/Physic/BodyExtender/LeftSideOffsetCreator.hpp>
#include <snake/Physic/BodyExtender/RightSideOffsetCreator.hpp>

namespace snake::physic::testing {
    
    class NearHeadBodyExtenderTest : public ::testing::Test {
    public:
        NearHeadBodyExtenderTest()
        : body( sf::Vector2f(0.f, 0.f), sf::Vector2f(1.f, 1.f) )
        , bodyExtender(&body) {
        
        }

        Body body;
        NearHeadBodyExtender bodyExtender;
    };
    
    TEST_F(NearHeadBodyExtenderTest, testExtendAtUp) {
        bodyExtender.extendFrom( UpSideOffsetCreator( &body.head() ));

        EXPECT_EQ(body.head().position.y, 1.f);
        EXPECT_THROW( bodyExtender.extendFrom(DownSideOffsetCreator( &body.head() )), std::logic_error); 
    }

    TEST_F(NearHeadBodyExtenderTest, testExtendAtDown) {
        bodyExtender.extendFrom( DownSideOffsetCreator( &body.head() ));
        
        EXPECT_EQ(body.head().position.y, -1.f);
        EXPECT_THROW( bodyExtender.extendFrom(UpSideOffsetCreator( &body.head() )), std::logic_error); 
    }
    
    TEST_F(NearHeadBodyExtenderTest, testExtendAtRight) {
        bodyExtender.extendFrom( RightSideOffsetCreator( &body.head() ));
        
        EXPECT_EQ(body.head().position.x, 1.f);
        EXPECT_THROW( bodyExtender.extendFrom(LeftSideOffsetCreator( &body.head() )), std::logic_error); 
    }
    
    TEST_F(NearHeadBodyExtenderTest, testExtendAtLeft) {
        bodyExtender.extendFrom( LeftSideOffsetCreator( &body.head() ));
        
        EXPECT_EQ(body.head().position.x, -1.f);
        EXPECT_THROW( bodyExtender.extendFrom(RightSideOffsetCreator( &body.head() )), std::logic_error); 
    }

}
