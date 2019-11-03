#include <snake/Physic/Body.hpp>

namespace snake::physic {

    Body::Body(sf::Vector2f headPosition, sf::Vector2f headSize) {
        components.emplace_back( PhysicComponent( std::move(headSize) ));
        head().position = headPosition;
    }
    
    void Body::shrink() {
        components.pop_back();
        components.back().prev = nullptr;
    }

    PhysicComponent& Body::cloneHead() {
        auto& head = components.front();
        components.emplace_front( head.clone() );

        head.next = &components.front();
        components.front().prev = &head;
        components.front().next = nullptr;

        return components.front();
    }

    PhysicComponent& Body::cloneTail() {
        auto& tail = components.back();
        components.emplace_back( tail.clone() );

        tail.prev = &components.back();
        components.back().next = &tail;
        components.back().prev = nullptr;

        return components.back();
    }

    PhysicComponent& Body::head() {
        return components.front();
    }

    PhysicComponent& Body::tail() {
        return components.back();
    }

    PhysicComponent& Body::operator[](unsigned index) {
        return components.at(index);
    }

    size_t Body::size() const {
        return components.size();
    }

    Body::iterator Body::begin() {
        return components.begin();
    }

    Body::iterator Body::end() {
        return components.end();
    }

}
