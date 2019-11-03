#ifndef RECTANGLESEGMENTSMODEL_H
#define RECTANGLESEGMENTSMODEL_H

#include <unordered_map>
#include <memory>
#include <SFML/Graphics/RenderTarget.hpp>
#include <snake/Physic/Body.hpp>
#include <snake/Renderer/Model.hpp>
#include <snake/Renderer/SizedShapeCreator.hpp>

namespace sf {
    
    class Shape;

}

namespace snake::renderer {
    
    template<typename ShapeType> 
    class ShapeModel : public Model {
    public:
        template<typename... Args>
        ShapeModel(physic::Body* body, float scale, Args&&... args)
        : scale(scale) {
            for (auto&& physicComponent : *body) {
                SizedShapeModelCreator<ShapeType> creaator(&physicComponent, scale);
                auto segmentRenderModel = creaator.create( std::forward<Args>(args)... );
                shapesToRender.emplace( std::make_pair(&physicComponent, std::move(segmentRenderModel) ));
            } 
        }

        void setColor(sf::Color const& color) override {
            for (auto&& [key, shape] : shapesToRender) {
                shape->setFillColor(color);
            } 
        }

        void setAnimation(animator::Animation<animator::TextureRectangleMapper> const& animation) override {
            for (auto&& [physicComponent, shape] : shapesToRender) {
                auto const& textureRect = animation.getTextureRect(physicComponent->position);
                shape->setTextureRect(textureRect);
            }
        }
        
        void setAnimation(sf::IntRect const& animation) override {
            for (auto&& shape : shapesToRender) {
                shape.second->setTextureRect(animation);
            }
        }

        void setTexture(const sf::Texture* texture, bool resetRect=false) override {
            for (auto&& [key, shape] : shapesToRender) {
                shape->setTexture(texture, resetRect);
            }
        }
        
        template<typename T, typename... Args> void changeModel(physic::PhysicComponent* component, Args&&... args) {
            if ( auto found = shapesToRender.find(component); found != shapesToRender.end() ) {
                SizedShapeModelCreator<T> creator(component, scale);
                auto newShape = creator.create( std::forward<Args>(args)... );
                found->second = std::move(newShape);
            }
        }
    private:
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
            for (auto&& [key, shape] : shapesToRender) {
                shape->setOrigin( key->origin.x * scale, key->origin.y * scale);
                shape->move( -key->origin.x * scale, -key->origin.y * scale);
                shape->rotate(key->angle);
                target.draw( *shape, states);
            }
        }
    private:
        std::unordered_map< physic::PhysicComponent*, std::unique_ptr<sf::Shape> > shapesToRender;
        float scale;
    };

}


#endif /* RECTANGLESEGMENTSMODEL_H */
