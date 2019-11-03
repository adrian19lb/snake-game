#include <gtest/gtest.h>
#include <snake/Core/detail/DefaultComponentsCreator.hpp>
#include <snake/Core/EntityComponentSystem/Component.hpp>

namespace snake::core::testing {

    TEST(EntityComponentsCreator, testCreateEntityWithComponents) {
        World world(sf::Vector2f(1.f, 1.f));
        DefaultComponentsCreator entityCreator(&world);

        auto entity = entityCreator.create<Component<int>, Component<float> >();        
        EXPECT_TRUE(entity->has< Component<int> >());
        EXPECT_TRUE(entity->has< Component<float >>());
        EXPECT_FALSE(entity->has< Component<char>>());
    }

}
