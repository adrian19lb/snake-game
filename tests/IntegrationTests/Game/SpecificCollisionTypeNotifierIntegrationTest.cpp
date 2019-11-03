#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <snake/Core/EntityComponentSystem/World.hpp>
#include <snake/Game/Entity/EntityWipeOuter.hpp>
#include <snake/Physic/Collision/CollisionProcessor.hpp>
#include <snake/Game/Teleport/CollisionTeleportComponentNotifier.hpp>
#include <snake/Game/Score/CollisionScoreComponentNotifier.hpp>
#include <snake/Game/Score/ScoreComputer.hpp>
#include <snake/Game/Teleport/EntityAcrossAxsisTeleporter.hpp>

namespace snake::game::testing {

    class MockEntityWipeOuter : public eventer::Receiver<ScoreEvent> {
    public:
        int callsNumber;

        MockEntityWipeOuter(eventer::EventManager* eventManager)
        : callsNumber(0) {
            eventManager->subscribe<ScoreEvent>(this);
        }

        void receive(ScoreEvent const& event) override {
            ++callsNumber;
        }
    };

    class SpecificCollisionTypeNotifierIntegrationTest : public ::testing::Test {
    public:
        SpecificCollisionTypeNotifierIntegrationTest()
        : world(sf::Vector2f(1.f, 1.f))
        , collisionProcessor(&eventManager, &world.getComponentsManager()) {
            world.registerReceiver(&collisionProcessor); 
        }

        eventer::EventManager eventManager;
        core::World world;
        physic::CollisionProcessor collisionProcessor;
    };
    
    TEST_F(SpecificCollisionTypeNotifierIntegrationTest, testScoreComputerIntegration) {
        ScoreComputer mockScoreComputer(&eventManager, &world);
        auto entity = world.create(std::make_unique<physic::Body>(), std::make_unique<OverallScoreComponent>());
        world.create(std::make_unique<physic::Body>(), std::make_unique<ScoreComponent>(10));
        collisionProcessor.add<CollisionScoreComponentNotifier>(entity);
        
        collisionProcessor.process();
        collisionProcessor.process();

        EXPECT_EQ(world.getComponentsManager().pull<OverallScoreComponent>(entity)->value, 2*10);
    }
    
    TEST_F(SpecificCollisionTypeNotifierIntegrationTest, testEntityWipeOuterIntegration) {
        MockEntityWipeOuter mockEntityWipeOuter(&eventManager);
        ScoreComputer scoreComputer(&eventManager, &world);
        
        auto entity = world.create(std::make_unique<physic::Body>(), std::make_unique<OverallScoreComponent>());
        world.create(std::make_unique<physic::Body>(), std::make_unique<ScoreComponent>(10));

        collisionProcessor.add<CollisionScoreComponentNotifier>(entity);
        collisionProcessor.process();

        EXPECT_EQ(mockEntityWipeOuter.callsNumber, 1);
    }
    
    TEST_F(SpecificCollisionTypeNotifierIntegrationTest, testEntityAcrosAxsisTeleportIntegration) {
        EntityAcrossAxsisTeleporter teleporter(&eventManager, &world);
        
        auto entity = world.create(std::make_unique<physic::Body>(sf::Vector2f(1.f, 1.f)));
        world.create(std::make_unique<physic::Body>(sf::Vector2f(1.f, 1.f)), std::make_unique<TeleportAcrossAxsisComponent>(new TeleportAcrossAxsisComponent::X(2.f)));

        collisionProcessor.add<CollisionTeleportComponentNotifier>(entity);
        collisionProcessor.process();
        
        auto entityBody = world.getComponentsManager().pull<physic::Body>(entity);
        EXPECT_EQ(entityBody->head().position, sf::Vector2f(2.f, 1.f));
    }

}
