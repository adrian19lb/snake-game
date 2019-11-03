#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <snake/Renderer/RenderComponents.hpp>
#include <snake/Game/System/GraphicsSystem.hpp>
#include <snake/Core/EntityComponentSystem/World.hpp>
#include <imgui_sfml/imgui.h>
#include <imgui_sfml/imgui-SFML.h>
#include <cassert>

namespace snake::game {
        
    GraphicsSystem::GraphicsSystem(sf::RenderWindow* window, core::World* world, eventer::EventManager* eventManager)
    : System(world)
    , scale(36.f)
    , resource(window, sf::Vector2i(scale, scale)) 
    , eventManager(eventManager)
    , componentsManager(&world->getComponentsManager()) {
        auto meshProcessor = std::make_unique<renderer::MeshProcesor>(scale, &resource);
        mesher = meshProcessor.get();
        System::add(std::make_unique<animator::AnimationProcessor>());
        System::add(std::move(meshProcessor));
        System::registerProcesorsToWorld();
    }
     
    void GraphicsSystem::initMap(core::EntityID id, std::string&& filename) {
        map = std::make_unique<renderer::Map>(&resource.textures.get(id), filename);
        map->create( sf::Vector2u(scale, scale) );
    }

    void GraphicsSystem::setTexture(const core::Entity* entity, std::string&& filename) {
        resource.textures.load(entity->id, std::forward<std::string>(filename));
    }
    
    void GraphicsSystem::setTextureRect(const core::Entity* entity, sf::Vector2i&& position) {
        resource.entitiesTextureRects.add(entity->id, std::forward<sf::Vector2i>(position));
    }
        
    void GraphicsSystem::setColor(const core::Entity* entity, sf::Color&& color) {
        auto renderComponent = componentsManager->pull<renderer::RenderComponents>(entity);
        assert(renderComponent && "Entity has not attached RenderComponents");
        renderComponent->fillColor = std::move(color);
    }
        
    void GraphicsSystem::process() {
        System::process();
        render();
    }

    void GraphicsSystem::render() {
        resource.window->clear();
        if(map) {
            resource.window->draw(*map);
        }
        mesher->draw(*resource.window);
        ImGui::SFML::Render(*resource.window);
        resource.window->display();
    }

}
