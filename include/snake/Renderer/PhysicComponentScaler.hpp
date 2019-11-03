#ifndef PHYSICCOMPONENTSCALER_H
#define PHYSICCOMPONENTSCALER_H

#include <snake/Physic/PhysicComponent.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <type_traits>

namespace snake::renderer {
    
    template<typename ShapeType> 
    class PhysicComponentScaler {
    public:
        PhysicComponentScaler(physic::PhysicComponent const* component, float scale)
        : component(component)
        , scale(scale) {
            
        }
            
        sf::Vector2f scalePosition() {
            return sf::Vector2f(scale*component->position.x, -scale*component->position.y);
        }

        template<typename U = ShapeType, typename std::enable_if_t< std::is_same<U, sf::RectangleShape>::value>* = nullptr>
        sf::Vector2f scaleSize() {
            return sf::Vector2f(scale*component->size.x, scale*component->size.y);
        }
        
        template<typename U = ShapeType, typename std::enable_if_t< std::is_same<U, sf::CircleShape>::value >* = nullptr>
        float scaleSize() {
            return 0.5*scale*component->size.x;
        }
     private:
        physic::PhysicComponent const* component;
        float scale;
    };

}



#endif /* PHYSICCOMPONENTSCALER_H */
