#include <snake/Renderer/MeshProcessor.hpp>
#include <snake/Renderer/RenderComponents.hpp>
#include <snake/Renderer/GraphicResources.hpp>
#include <snake/Animator/AnimationComponent.hpp>
#include <snake/Core/EntityComponentSystem/ProcesorVisitor.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>

namespace snake::renderer {
    
    MeshProcesor::MeshProcesor(float& scale, GraphicsResource* graphicResources)
    : scale(scale)
    , graphicResources(graphicResources) {
        
    }
    
    void MeshProcesor::add(core::EntityID id, value_type value) {
        modelFactory[id] = value;
    }
        
    void MeshProcesor::enter(core::ProcesorVisitor* visitor) {
        visitor->visit(this); 
    }
    
    void MeshProcesor::update(core::Entity *const entity, core::ComponentsManager* components) {     
        auto body = components->pull<physic::Body>(entity); 
        auto model = modelFactory.at(entity->id)(body, scale);
        auto renderComponents = components->pull<RenderComponents>((entity));
        renderComponents->texture = &graphicResources->textures.get(entity->id);
        models.emplace_back(std::move(model));
        trySetUpLastMeshModelWithRenderComponent(entity, components->pull<RenderComponents>(entity));
        setAnimationToLastMeshModelIfEntityHas(entity, components);
    }

    void MeshProcesor::trySetUpLastMeshModelWithRenderComponent(core::Entity *const entity, RenderComponents* renderComponent) {
        try {
            auto& model = models.back();
            model->setColor(renderComponent->fillColor);
            model->setTexture(&graphicResources->textures.get(entity->id));
            model->setAnimation(*graphicResources->entitiesTextureRects.create(entity->id));
        }catch(std::out_of_range const& e) {
            // std::cerr << "MeshProcesor::update::" << e.what() << std::endl; 
        } 
    }

    void MeshProcesor::setAnimationToLastMeshModelIfEntityHas(core::Entity *const entity, core::ComponentsManager* components) {
        if (entity->has<animator::AnimationComponent>()) {
            auto& model = models.back();
            auto animationComponent = components->pull<animator::AnimationComponent>(entity);
            model->setAnimation(*animationComponent->animation); 
        }
    }

    bool MeshProcesor::doesContainComponents(const core::Entity *const entity) const {
        return entity->has<physic::Body, RenderComponents>(); 
    }
        
    void MeshProcesor::draw(sf::RenderTarget& target) {
        for (auto&& model : models) {
            target.draw(*model); 
        }

        models.clear();
    }

}
