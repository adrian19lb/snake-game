#include <gtest/gtest.h>
#include <snake/Physic/Body.hpp>
#include <snake/Physic/BodyExtender/NearTailBodyExtender.hpp>
#include <snake/Physic/BodyExtender/LeftSideOffsetCreator.hpp>
#include <snake/Physic/Collision/BodyCollisionDetector.hpp>

namespace snake::physic::testing {
    
    class BodyCollisionComponentTest : public ::testing::Test {
    public:
       void SetUp() override {
            body = new Body(sf::Vector2f(5.f, 5.f), sf::Vector2f(1.f, 4.f));
            NearTailBodyExtender tailExtender(body);
            
            tailExtender.extendFrom(LeftSideOffsetCreator(&body->tail()));
            tailExtender.extendFrom(LeftSideOffsetCreator(&body->tail()));
       }

       void TearDown() override {
           delete body;
       }

    public:
       Body* body;
    };

    TEST_F(BodyCollisionComponentTest, testIfBodyOverlapWithAnother) {
        Body collidableBody(sf::Vector2f(7.f, 5.f));
        NearTailBodyExtender tailExtender(&collidableBody);
        tailExtender.extendFrom(LeftSideOffsetCreator(&collidableBody.tail()));
        tailExtender.extendFrom(LeftSideOffsetCreator(&collidableBody.tail()));

        BodyCollisionDetector collisionDetector(body);
        EXPECT_TRUE(collisionDetector.isAnyPhysicComponentOverlapedIn(&collidableBody));
        
    }

    TEST_F(BodyCollisionComponentTest, testIfBodyNoOverlapWithAnother) {
        Body collidableBody(sf::Vector2f(2.f, 5.f));
        NearTailBodyExtender tailExtenderThree(&collidableBody);
        tailExtenderThree.extendFrom(LeftSideOffsetCreator(&collidableBody.tail()));
        tailExtenderThree.extendFrom(LeftSideOffsetCreator(&collidableBody.tail()));

        BodyCollisionDetector collisionDetector(body);
        EXPECT_FALSE(collisionDetector.isAnyPhysicComponentOverlapedIn(&collidableBody));
    }
    
}
