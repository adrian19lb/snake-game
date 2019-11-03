#include <snake/Physic/Movement/WormMoveBehaviour.hpp>
#include <gtest/gtest.h>

namespace snake::physic::testing {

    TEST(WormMoveBehaviourTest, testMoveUp) {
        Body body( sf::Vector2f(0.f, 0.f), sf::Vector2f(1.f, 1.f) );
        WormMoveBehaviour wormMovement(&body);

        wormMovement.moveUp(1.f);

        EXPECT_EQ( body.head().position, sf::Vector2f(0.f, 1.f) );
    }

    TEST(WormMoveBehaviourTest, testMoveDown) {
        Body body( sf::Vector2f(0.f, 0.f), sf::Vector2f(1.f, 1.f) );
        WormMoveBehaviour wormMovement(&body);

        wormMovement.moveDown(1.f);

        EXPECT_EQ( body.head().position, sf::Vector2f(0.f, -1.f) );
    }
    
    TEST(WormMoveBehaviourTest, testMoveRight) {
        Body body( sf::Vector2f(0.f, 0.f), sf::Vector2f(1.f, 1.f) );
        WormMoveBehaviour wormMovement(&body);

        wormMovement.moveRight(1.f);

        EXPECT_EQ( body.head().position, sf::Vector2f(1.f, 0.f) );
    }
    
    TEST(WormMoveBehaviourTest, testMoveLeft) {
        Body body( sf::Vector2f(0.f, 0.f), sf::Vector2f(1.f, 1.f) );
        WormMoveBehaviour wormMovement(&body);

        wormMovement.moveLeft(1.f);

        EXPECT_EQ( body.head().position, sf::Vector2f(-1.f, 0.f) );
    }
}
