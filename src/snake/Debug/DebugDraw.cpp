#include <snake/Core/EntityComponentSystem/World.hpp>
#include <snake/Game/Score/ScorableEntityRandomPositionMaker.hpp>
#include <snake/Game/Score/ScoreComputer.hpp>
#include <snake/Game/Score/ScoredEntityBodyExtender.hpp>
#include <snake/Game/Teleport/EntityAcrossAxsisTeleporter.hpp>
#include <snake/Debug/DebugDraw.hpp>
#include <snake/Debug/PlayerPhysicWidget.hpp>
#include <snake/Game/Entity/EntityAbstractCreatorImpl.hpp>
#include <snake/Game/Score/ScoreComputer.hpp>
#include <snake/Game/Teleport/EntityAcrossAxsisTeleporter.hpp>
#include <snake/Game/Score/ScoredEntityBodyExtender.hpp>
#include <snake/Game/Score/ScorableEntityRandomPositionMaker.hpp>

namespace snake::debug {

    DebugDraw::DebugDraw()
    : window( sf::VideoMode(800,600), "DebugDraw" )
    , eventManager()
    , world(sf::Vector2f(16.f, 22.f))
    , graphics(&window, &world, &eventManager)
    , physics(1, &world, &eventManager)
    , collisionResponsers(&eventManager, &world) {
        window.setVerticalSyncEnabled(true);
        createCollisionReceivers();
        createEntities();
    }

    void DebugDraw::createEntities() {
        auto entityCreator = std::make_unique<game::EntityAbstractCreatorImpl>(&physics, &graphics, &world);
        player = entityCreator->createPlayer();
        entityCreator->createApple();
        entityCreator->createMap();
        entityCreator->createWall(game::Side::North);
        entityCreator->createWall(game::Side::South);
        entityCreator->createWall(game::Side::East);
        entityCreator->createWall(game::Side::West);
    }

    void DebugDraw::createCollisionReceivers() {
        collisionResponsers.create<game::ScoreComputer>();
        collisionResponsers.create<game::ScoredEntityBodyExtender>();
        collisionResponsers.create<game::ScorableEntityRandomPositionMaker>();
        collisionResponsers.create<game::EntityAcrossAxsisTeleporter>();
    }

    void DebugDraw::process() {
        ImGui::SFML::Init(window);
        sf::Time accumulator = sf::Time::Zero;
        sf::Clock timer;
        sf::Time timeStep = sf::seconds(1.f/15.f);
        while (window.isOpen()) {
            handleInput( dt.getElapsedTime().asSeconds() );
            ImGui::SFML::Update(window, dt.restart());
            
            accumulator += timer.restart();
            while (accumulator >= timeStep) {
                physics.process();
                accumulator -= timeStep;
            }

            showDebugMenuBar();
            ImGui::ShowTestWindow();
            graphics.process();
        }
        ImGui::SFML::Shutdown();    
   }

    void DebugDraw::showDebugMenuBar() {
       static bool isPhysicsPlayerItemActive = false;

       if (ImGui::BeginMainMenuBar()) {
           if (ImGui::BeginMenu("DebugDraw")) {
               ImGui::MenuItem("Player", NULL, &isPhysicsPlayerItemActive);
               ImGui::EndMenu();
           }
           ImGui::EndMainMenuBar(); 
       }    

       if (isPhysicsPlayerItemActive) {
           PlayerPhysicWidget playerPhysicWidget(player, &eventManager, &world);
           playerPhysicWidget.show(nullptr);
       }

    }

    void DebugDraw::handleInput(float dt) {
        sf::Event event;
        while ( window.pollEvent(event) ) {
            ImGui::SFML::ProcessEvent(event);    
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

}
