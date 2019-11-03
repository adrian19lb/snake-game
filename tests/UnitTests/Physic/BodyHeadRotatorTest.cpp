#include <gtest/gtest.h>
#include <snake/Physic/Rotation/BodyHeadRotator.hpp>
#include <snake/Physic/BodyExtender/NearTailBodyExtender.hpp>
#include <snake/Physic/BodyExtender/LeftSideOffsetCreator.hpp>

namespace snake::physic::testing {
   
    TEST(BodyHeadRotatorTest, testHeadRotation) {
        Body body(sf::Vector2f(0.f, 0.f), sf::Vector2f(1.f, 1.f)); 
        BodyHeadRotator rotator(&body);
        EXPECT_EQ(0.f, rotator.getAngle() );
        
        body.head().position += sf::Vector2f(1.f, 0.f);
        EXPECT_EQ(0.f, rotator.getAngle() );
        body.head().position += sf::Vector2f(-1.f, 0.f);
        EXPECT_EQ(-180.f, rotator.getAngle() );
        body.head().position += sf::Vector2f(0.f, -1.f);
        EXPECT_EQ(90.f, rotator.getAngle() );
        body.head().position += sf::Vector2f(0.f, 1.f);
        EXPECT_EQ(-90.f, rotator.getAngle() );
    }
    
    TEST(BodyHeadRotatorTest, testHeadRotationWhenDetachHead) {
        Body body(sf::Vector2f(0.f, 0.f), sf::Vector2f(1.f, 1.f)); 
        body.cloneTail();
        body.head().position = sf::Vector2f(5.f, 5.f);
        
        BodyHeadRotator rotator(&body);
        EXPECT_EQ(0.f, rotator.getAngle() );
        
        body.head().position += sf::Vector2f(1.f, 0.f);
        EXPECT_EQ(0.f, rotator.getAngle() );
        body.head().position += sf::Vector2f(-1.f, 0.f);
        EXPECT_EQ(-180.f, rotator.getAngle() );
        body.head().position += sf::Vector2f(0.f, -1.f);
        EXPECT_EQ(90.f, rotator.getAngle() );
        body.head().position += sf::Vector2f(0.f, 1.f);
        EXPECT_EQ(-90.f, rotator.getAngle() );
    }


}
