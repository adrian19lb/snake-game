#include <gtest/gtest.h>
#include <snake/Animator/BodyStatesAnimator.hpp>
#include <snake/Animator/TextureRectFactory.hpp>
#include <snake/Physic/Movement/WormMoveBehaviour.hpp>
#include <snake/Physic/BodyExtender/NearTailBodyExtender.hpp>
#include <snake/Physic/BodyExtender/LeftSideOffsetCreator.hpp>
#include <snake/Animator/States/BodyAnimationState.hpp>
#include <snake/Animator/States/HeadAnimationState.hpp>
#include <snake/Animator/States/TailAnimationState.hpp>
#include <snake/Animator/States/SpecificPositionAnimationState.hpp>

namespace snake::animator::testing {
    
    class BodyStateAnimatorTest : public ::testing::Test {
    public:
        enum class Body {
               Head,
               Default,
               Tail,
               Custom
        }; 
    public:
        BodyStateAnimatorTest()
        : body( sf::Vector2f(0.f,0.f) )
        , textureRectFactory( sf::Vector2i() ) {
        
        }

        void SetUp() override {
            extendBody();
            initTextureRectFactory();
        }
    private:
        void extendBody() {
            physic::NearTailBodyExtender tailExtender(&body);
            tailExtender.extendFrom(physic::LeftSideOffsetCreator(&body.tail()));
            tailExtender.extendFrom(physic::LeftSideOffsetCreator(&body.tail()));
            tailExtender.extendFrom(physic::LeftSideOffsetCreator(&body.tail()));
        }

        void initTextureRectFactory() {
            textureRectFactory.add(Body::Head, sf::Vector2i(5, 0) );
            textureRectFactory.add(Body::Default, sf::Vector2i(10, 0) );
            textureRectFactory.add(Body::Tail, sf::Vector2i(15, 0) );
            textureRectFactory.add(Body::Custom, sf::Vector2i(20, 0) );
        }
    public:    
        physic::Body body;
        animator::TextureRectFactory<Body, int> textureRectFactory;
    };

    TEST_F(BodyStateAnimatorTest, testAnimateBody) {
        physic::WormMoveBehaviour bodyMoveComponent(&body);
        animator::BodyStateAnimator animator(&body);

        animator.push<animator::BodyAnimationState>( &body, textureRectFactory.create(Body::Default) );
        animator.push<animator::HeadAnimationState>( &body, textureRectFactory.create(Body::Head) );
        animator.push<animator::TailAnimationState>( &body, textureRectFactory.create(Body::Tail) );
        animator.push<animator::SpecificPositionAnimationState>( textureRectFactory.create(Body::Custom), sf::Vector2f(-1.f, 0.f));
        
        bodyMoveComponent.moveRight(1.f);
        animator.animate();
        animator.animate();
        auto& bodyAnimation = animator.getAnimation();
        
        EXPECT_THROW( bodyAnimation.getTextureRect( sf::Vector2f(2.f, 0.f)), std::out_of_range);
        EXPECT_EQ( *textureRectFactory.create(Body::Head), bodyAnimation.getTextureRect( sf::Vector2f(1.f, 0.f)) );
        EXPECT_EQ( *textureRectFactory.create(Body::Default), bodyAnimation.getTextureRect( sf::Vector2f(0.f, 0.f)) );
        EXPECT_EQ( *textureRectFactory.create(Body::Custom), bodyAnimation.getTextureRect( sf::Vector2f(-1.f, 0.f)) );
        EXPECT_EQ( *textureRectFactory.create(Body::Tail), bodyAnimation.getTextureRect( sf::Vector2f(-2.f, 0.f)) );
        EXPECT_THROW( bodyAnimation.getTextureRect( sf::Vector2f(-3.f, 0.f)), std::out_of_range);
    }
    
    TEST_F(BodyStateAnimatorTest, testAnimateWithoutCalling) {
        animator::BodyStateAnimator animator(&body);
        
        auto& nullAnimation = animator.getAnimation();

        EXPECT_EQ( sf::IntRect(), nullAnimation.getTextureRect( sf::Vector2f(0.f, 0.f) ));
        EXPECT_EQ( sf::IntRect(), nullAnimation.getTextureRect( sf::Vector2f(-1.f, 0.f) ));
        EXPECT_EQ( sf::IntRect(), nullAnimation.getTextureRect( sf::Vector2f(-2.f, 0.f) ));
        EXPECT_EQ( sf::IntRect(), nullAnimation.getTextureRect( sf::Vector2f(-3.f, 0.f) ));
    }

}
