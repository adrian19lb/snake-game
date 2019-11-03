#ifndef ENTITYABSTRACTCREATORIMPL_H
#define ENTITYABSTRACTCREATORIMPL_H

#include <SFML/System/Vector2.hpp>
#include <snake/Game/Entity/EntityAbstractCreator.hpp>
#include <snake/Game/System/PhysicsSystem.hpp>
#include <snake/Game/System/GraphicsSystem.hpp>
#include <snake/Core/EntityComponentSystem/World.hpp>

namespace snake::game {

    class TeleportWallAttributes;
    class TeleportAcrossAxsisComponent;

    class EntityAbstractCreatorImpl : public EntityAbstractCreator {
    public:
        EntityAbstractCreatorImpl(PhysicsSystem* physics, GraphicsSystem* graphics, core::World* world);
        
        core::Entity* createPlayer() override;
   private:
        template<typename T> void registerPlayerCreatorToEngines(T* playerCreator) {
            physics->enter(playerCreator);
            graphics->enter(playerCreator);
        }

        void addPlayerTextureRects();
   public:
        core::Entity* createApple() override;

        core::Entity* createMap() override;

        core::Entity* createWall(Side id) override;
    private:
        std::unique_ptr<TeleportWallAttributes> createWallAttribbutes(Side id) const;
        std::unique_ptr<TeleportAcrossAxsisComponent> createTeleportAcrossAxisComponent(Side id, float cord) const;
    private:
        const float WALL_WIDTH;
        const sf::Vector2f NORTH_SOUTH_WALL_SIZE;
        const sf::Vector2f EAST_WEST_WALL_SIZE;
        std::map<Side, float> teleport;
        game::GraphicsSystem* graphics;
        game::PhysicsSystem* physics;
        core::World* world;
    };

}

#endif /* ENTITYABSTRACTCREATORIMPL_H */
