#ifndef DEBUGDRAW_HPP
#define DEBUGDRAW_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <imgui_sfml/imgui.h>
#include <imgui_sfml/imgui-SFML.h>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Clock.hpp>
#include <snake/Core/EntityComponentSystem/World.hpp>
#include <snake/Eventer/EventManager.hpp>
#include <snake/Game/System/PhysicsSystem.hpp>
#include <snake/Game/System/GraphicsSystem.hpp>
#include <snake/Game/CollisionResponserComposite.hpp>

namespace snake::debug {
    
    class DebugDraw {
    public:
        DebugDraw();
        void process();
    private:
        void createEntities();
        void createCollisionReceivers();
        void showDebugMenuBar();
        void handleInput(float dt);
        void render();
    private:
        sf::RenderWindow window;
        sf::Clock dt;
        eventer::EventManager eventManager;
        core::World world;
        game::GraphicsSystem graphics;
        game::PhysicsSystem physics;
        core::Entity* player;
        game::CollisionResponserComposite collisionResponsers;     
    };

}

#endif /* ifndef DEBUGDRAW_HPP */
