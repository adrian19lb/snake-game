#include <snake/Physic/Movement/WormMoveBehaviour.hpp>

namespace snake::physic {

    WormMoveBehaviour::WormMoveBehaviour(Body* body)
    : body(body) {

    }

    void WormMoveBehaviour::moveUp(float dt) {
        makeMovement( sf::Vector2f(0.f, getHeadSize().y) );
    }

    void WormMoveBehaviour::moveDown(float dt) {
        makeMovement(sf::Vector2f(0.f, -getHeadSize().y));
    }

    void WormMoveBehaviour::moveRight(float dt) {
        makeMovement(sf::Vector2f( getHeadSize().x, 0.f) );
    }

    void WormMoveBehaviour::moveLeft(float dt) {
        makeMovement(sf::Vector2f( -getHeadSize().x, 0.f) );
    }

    sf::Vector2f const& WormMoveBehaviour::getHeadSize() const {
        return body->head().size; 
    }

    void WormMoveBehaviour::makeMovement(sf::Vector2f&& movement) {
        auto& clonedHead = body->cloneHead();
        clonedHead.position += movement;
        body->shrink();
    }

}
