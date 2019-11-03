#include <gtest/gtest.h>
#include <snake/Core/EntityComponentSystem/World.hpp>
#include <snake/Core/EntityComponentSystem/Procesor.hpp>
#include <snake/Core/EntityComponentSystem/Component.hpp>
#include <cassert>

namespace snake::core::testing {
    
    struct DummyComponent : public Component<DummyComponent> {
        int value = 10;
    };

    class MockProcesor : public Procesor {
    private:
        int counter = 0;
    protected:
        void update(Entity *const entity, ComponentsManager* manager) override {
            auto component = manager->pull<DummyComponent>(entity);
            assert(component);
            ++counter;
        }

        void enter(ProcesorVisitor* visitor) override {
            
        }

        bool doesContainComponents(const Entity *const entity) const override {
            return entity->has<DummyComponent>(); 
        }
    public:
        int callsNumberUpdateEntityWithDummyComponent() const {
            return counter;
        } 
    };

    
    TEST(WorldTest, testAttachAndDetachComponentsToEntity) {
        World* world = new World(sf::Vector2f(1.f, 1.f));
        MockProcesor procesor;

        world->registerReceiver(&procesor);
        
        core::Entity *const entity = world->create( std::make_unique<DummyComponent>() );

        procesor.process();
        EXPECT_EQ(1, procesor.callsNumberUpdateEntityWithDummyComponent() );
        
        world->detach<DummyComponent>(entity);
        procesor.process();
        EXPECT_EQ(1, procesor.callsNumberUpdateEntityWithDummyComponent() );
        
        world->attach<DummyComponent>(entity); 
        procesor.process();
        EXPECT_EQ(2, procesor.callsNumberUpdateEntityWithDummyComponent() );
        
        world->erase(entity);
        procesor.process();
        EXPECT_EQ(2, procesor.callsNumberUpdateEntityWithDummyComponent() );
        delete world;
    }

    TEST(WorldTest, testUpdateEntityIfWorldWasDeleted) {
        World* world = new World(sf::Vector2f(1.f,1.f));
        MockProcesor procesor;

        world->registerReceiver(&procesor);
        
        auto* entity = world->create( std::make_unique<DummyComponent>() );
        delete world;
        procesor.process();
    }

    TEST(WorldTest, testRegisterReceiverAfterEntityCreation) {
        World* world = new World(sf::Vector2f(1.f,1.f));
        MockProcesor procesor;
        
        auto* entity = world->create( std::make_unique<DummyComponent>() );
        world->registerReceiver(&procesor);
        procesor.process();
        EXPECT_EQ(1, procesor.callsNumberUpdateEntityWithDummyComponent() );
        delete world;
    }
    
    
}
