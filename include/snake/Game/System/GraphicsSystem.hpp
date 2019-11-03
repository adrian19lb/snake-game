#ifndef GRAPHICSSYSTEM_H
#define GRAPHICSSYSTEM_H

#include <snake/Eventer/EventManager.hpp>
#include <snake/Core/ResourceHolder.hpp>
#include <snake/Animator/AnimationProcessor.hpp>
#include <snake/Animator/TextureRectFactory.hpp>
#include <snake/Animator/TextureRectID.hpp>
#include <snake/Renderer/MeshProcessor.hpp>
#include <snake/Renderer/Map.hpp>
#include <snake/Renderer/GraphicResources.hpp>
#include <snake/Game/System/System.hpp>

namespace sf {

    class RenderWindow;
}

namespace snake::game {
    
    class GraphicsSystem : public System {
    public:    
        GraphicsSystem(sf::RenderWindow* window, core::World* world, eventer::EventManager* eventManager);
    public:
        void initPlayer(core::EntityID id) { }
        void initMap(core::EntityID id, std::string&& filename);
        template<template<typename T> class MeshModel, typename Shape> void setMeshModel(const core::Entity* entity) {
            mesher->add(entity->id, [](physic::Body* body, float scale) { 
                return std::make_unique< MeshModel<Shape> >(body, scale); 
            });
        }
        void setTexture(const core::Entity* entity, std::string&& filename);
        void setTextureRect(const core::Entity* entity, animator::TextureRect id, sf::Vector2i&& position);
        void setTextureRect(const core::Entity* entity, sf::Vector2i&& position);
        void setColor(const core::Entity* entity, sf::Color&& color);
        void process() override;
    private:
        void render();
    public:
        float scale;
        renderer::GraphicsResource resource;
    private:
        eventer::EventManager* eventManager;
        std::unique_ptr<renderer::Map> map;
        renderer::MeshProcesor* mesher;
        core::ComponentsManager* componentsManager;
    };

}

#endif /* GRAPHICSSYSTEM_H */
