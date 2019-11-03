#ifndef BODY_H
#define BODY_H

#include <snake/Core/EntityComponentSystem/Component.hpp>
#include <snake/Physic/PhysicComponent.hpp>
#include <deque>

namespace snake::physic {

    class Body : public core::Component<PhysicComponent> {
        using iterator = std::deque<PhysicComponent>::iterator;
    public:
        Body(sf::Vector2f headPosition = sf::Vector2f(3.f, -4.f), sf::Vector2f headSize = sf::Vector2f(1.f, 1.f));
        void shrink();
        PhysicComponent& cloneHead();
        PhysicComponent& cloneTail();
        PhysicComponent& head();
        PhysicComponent& tail();
        PhysicComponent& operator[](unsigned index);
        size_t size() const;
        iterator begin();
        iterator end();
    private:
        std::deque<PhysicComponent> components;
    };
}

#endif /* BODY_H */
