#include <snake/Physic/PhysicComponent.hpp>
#include <utility>

namespace snake::physic {
        
    PhysicComponent::PhysicComponent(sf::Vector2f&& size)
    : position()
    , origin(0.5f, 0.5f)
    , angle(0.f)
    , size(size)
    , prev(nullptr)
    , next(nullptr) {
        
    }

    PhysicComponent::PhysicComponent(PhysicComponent const& component)
    : position(component.position)
    , origin(component.origin)
    , angle(component.angle)
    , size(component.size)
    , prev(component.prev)
    , next(component.next) {
        
    }

    PhysicComponent::PhysicComponent(PhysicComponent&& component)
    : position( std::move(component.position) )
    , origin( std::move(component.origin) )
    , angle(component.angle)
    , size( std::move(component.size) )
    , prev(component.prev)
    , next(component.next) {
        component.prev = nullptr;
        component.next = nullptr;
    }

    PhysicComponent& PhysicComponent::operator=(PhysicComponent&& component) {
        this->position = std::move(component.position);
        this->origin = std::move(component.origin);
        this->angle = component.angle;
        this->size = std::move(component.size);
        this->prev = component.prev;
        this->next = component.next;
        component.prev = nullptr;
        component.next = nullptr;

        return *this;
    }

    PhysicComponent PhysicComponent::clone() {
        return PhysicComponent(*this);
    } 

}
