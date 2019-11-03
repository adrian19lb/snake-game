#include <SFML/System/Vector2.hpp>
#include <snake/Core/EntityComponentSystem/EntityCreator.hpp>
#include <snake/Game/Entity/EntityAbstractCreatorImpl.hpp>
#include <snake/Game/Entity/EntityProcessorsAttacher.hpp>
#include <snake/Game/Entity/PlayerProcessorsAttacher.hpp>
#include <snake/Game/Teleport/TeleportAcrossAxisComponent.hpp>
#include <snake/Game/Score/OverallScoreComponent.hpp>
#include <snake/Animator/AnimationComponent.hpp>
#include <snake/Physic/Movement/ConstantMovementComponent.hpp>
#include <snake/Game/Score/ScoredEntityBodyExtender.hpp>
#include <snake/Game/Score/ScoreComponent.hpp>
#include <snake/Renderer/RenderComponents.hpp>
#include <snake/Renderer/ShapeModel.hpp>

namespace snake::game {

    struct TeleportWallAttributes {
        const float teleportCoord;

        const sf::Vector2f size;

        const sf::Vector2f position;

        TeleportWallAttributes(float teleportCoord, sf::Vector2f const& size, sf::Vector2f const& position)
        : teleportCoord(teleportCoord)
        , size(size)
        , position(position) {
        
        }

        virtual Side getSide() const = 0;
    };

    struct NorthTeleportWallAttributes : public TeleportWallAttributes {

        NorthTeleportWallAttributes(core::World const& world)
        : TeleportWallAttributes(-world.getSize().x - 1.f, sf::Vector2f(world.getSize().y + 2.f, 1.f), world.getOrigin()){
        }

        Side getSide() const override {
            return Side::North;
        }
    };
    
    struct SouthTeleportWallAttributes : public TeleportWallAttributes {
        
        SouthTeleportWallAttributes(core::World const& world)
        : TeleportWallAttributes( -world.getOrigin().y - 1.f, 
                                  sf::Vector2f(world.getSize().y + 2.f, 1.f), 
                                  sf::Vector2f(world.getOrigin().x + 1.f, -world.getSize().y - 2.f)) {
        }

        Side getSide() const override {
            return Side::South;
        }
    };
    
    struct EastTeleportWallAttributes : public TeleportWallAttributes {
        
        EastTeleportWallAttributes(core::World const& world)
        : TeleportWallAttributes( world.getOrigin().x + 1.f, 
                                  sf::Vector2f(1.f, world.getSize().x + 2.f), 
                                  sf::Vector2f(world.getSize().y + 1.f, -world.getOrigin().x - 1.f)) {
        }

        Side getSide() const override {
            return Side::East;
        }
    };
    
    struct WestTeleportWallAttributes : public TeleportWallAttributes {
        
        WestTeleportWallAttributes(core::World const& world)
        : TeleportWallAttributes( world.getSize().y, 
                                  sf::Vector2f(1.f, world.getSize().x + 2.f), 
                                  world.getOrigin()) {
        }

        Side getSide() const override {
            return Side::West;
        }
    };
        
    EntityAbstractCreatorImpl::EntityAbstractCreatorImpl(game::PhysicsSystem* physics, game::GraphicsSystem* graphics, core::World* world)
    : WALL_WIDTH(1.f)
    , NORTH_SOUTH_WALL_SIZE(world->getSize().y + 2, WALL_WIDTH)
    , EAST_WEST_WALL_SIZE(WALL_WIDTH, world->getSize().x + 2)
    , graphics(graphics)
    , physics(physics)
    , world(world) {
        addPlayerTextureRects();
        teleport[Side::North] = -(world->getSize().x + 1.f);
        teleport[Side::South] = -(world->getOrigin().y + 1.f);
        teleport[Side::East] = world->getOrigin().x + 1.f;
        teleport[Side::West] = world->getSize().y;
    }

    core::Entity* EntityAbstractCreatorImpl::createPlayer() {
            core::EntityCreator< physic::Body, physic::ConstantMovementComponent, renderer::RenderComponents, animator::AnimationComponent, OverallScoreComponent, 
                                 physic::ExtendedBodyComponent> playerCreator(world);
            registerPlayerCreatorToEngines(&playerCreator);
            auto playerProcessorsAttacher = std::make_unique<PlayerProcessorsAttacher>(&world->getComponentsManager(), &graphics->resource.textureRects);
            auto player = playerCreator.create<EntityProcessorsAttacher>(std::move(playerProcessorsAttacher));
            graphics->resource.textures.load(player->id, "media/texture/player.png");

            return player;
        }

    void EntityAbstractCreatorImpl::addPlayerTextureRects() {
        graphics->resource.textureRects.add(animator::TextureRect::Head, sf::Vector2i(108, 0));
        graphics->resource.textureRects.add(animator::TextureRect::Body, sf::Vector2i(36, 0));
        graphics->resource.textureRects.add(animator::TextureRect::Tail, sf::Vector2i(0, 0));
    }
        
    core::Entity* EntityAbstractCreatorImpl::createApple() {
        auto apple = world->create(std::make_unique<physic::Body>(), std::make_unique<renderer::RenderComponents>(), std::make_unique<game::ScoreComponent>(10));
        physics->setPosition(apple, sf::Vector2f(4.f, -5.f));
        graphics->setTexture(apple, "media/texture/apple.png");
        graphics->setTextureRect(apple, sf::Vector2i(0, 0));
        graphics->setMeshModel<renderer::ShapeModel, sf::RectangleShape>(apple);
            
        return apple; 
     }

     core::Entity* EntityAbstractCreatorImpl::createMap() {
        auto map = world->create();
        graphics->setTexture(map, "media/texture/grass.png");
        graphics->initMap(map->id, "media/map/Map.txt");

        return map;
     }

     core::Entity* EntityAbstractCreatorImpl::createWall(Side id) {
        auto wall = createWallAttribbutes(id);
        auto teleportAcrossAxisComponent = createTeleportAcrossAxisComponent(id, wall->teleportCoord);
        
        return world->create(std::make_unique<physic::Body>(wall->position, wall->size), std::move(teleportAcrossAxisComponent));
     }

     std::unique_ptr<TeleportWallAttributes> EntityAbstractCreatorImpl::createWallAttribbutes(Side id) const {
         switch (id) {
            case Side::North:
                return std::make_unique<NorthTeleportWallAttributes>(*world);
            case Side::South:
                return std::make_unique<SouthTeleportWallAttributes>(*world);
            case Side::East:
                return std::make_unique<EastTeleportWallAttributes>(*world);
            case Side::West:    
                return std::make_unique<WestTeleportWallAttributes>(*world);
         }   
     }

     std::unique_ptr<TeleportAcrossAxsisComponent> EntityAbstractCreatorImpl::createTeleportAcrossAxisComponent(Side id, float cord) const {
         if(id == Side::North || id == Side::South) {
            return std::make_unique<game::TeleportAcrossAxsisComponent>(new game::TeleportAcrossAxsisComponent::Y(cord));
         }else {
            return std::make_unique<game::TeleportAcrossAxsisComponent>(new game::TeleportAcrossAxsisComponent::X(cord));
         }
     }

}
