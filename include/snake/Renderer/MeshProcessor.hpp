#ifndef RENDERER_H
#define RENDERER_H

#include <map>
#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <snake/Core/EntityComponentSystem/Procesor.hpp>
#include <snake/Core/EntityComponentSystem/ComponentsManager.hpp>
#include <snake/Physic/Body.hpp>
#include <snake/Renderer/GraphicResources.hpp>
#include <snake/Renderer/Model.hpp>

namespace snake::renderer {

    class RenderComponents;
    
    class MeshProcesor : public core::Procesor {
    public:
        using ModelUPtr = std::unique_ptr<Model>;
        using value_type = std::function<ModelUPtr(physic::Body*, float)>;
    public:
        MeshProcesor(float& scale, GraphicsResource* graphicResource);
        void add(core::EntityID id, value_type value);
        void enter(core::ProcesorVisitor* visitor) override;
        void draw(sf::RenderTarget& target);
    protected:
        bool doesContainComponents(const core::Entity *const entity) const override;
        void update(core::Entity *const entity, core::ComponentsManager* components) override;     
    private:
        void trySetUpLastMeshModelWithRenderComponent(core::Entity *const entity, RenderComponents* renderComponent);
        void setAnimationToLastMeshModelIfEntityHas(core::Entity *const entity, core::ComponentsManager* components);
    private:
        float& scale;
        std::map<core::EntityID, value_type> modelFactory;
        GraphicsResource* graphicResources;
        std::vector<ModelUPtr> models;
    };

}

#endif /* RENDERER_H */
