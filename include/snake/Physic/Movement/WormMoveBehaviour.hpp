#ifndef WORMMOVEBEHAVIOUR_H
#define WORMMOVEBEHAVIOUR_H

#include <snake/Physic/Body.hpp>
#include <snake/Physic/Movement/MoveBehaviour.hpp>

namespace snake::physic {

    class WormMoveBehaviour : public MoveBehaviour {
    public:
        WormMoveBehaviour(Body* body);
        
        void moveUp(float dt) override;

        void moveDown(float dt) override;

        void moveRight(float dt) override;

        void moveLeft(float dt) override;
    private:
        sf::Vector2f const& getHeadSize() const;
        void makeMovement(sf::Vector2f&& movement);
    private:
        Body* body;
    };  

}


#endif /* WORMMOVEBEHAVIOUR_H */
