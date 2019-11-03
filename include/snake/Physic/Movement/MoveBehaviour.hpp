#ifndef MOVEBEAHVIOUR_H
#define MOVEBEAHVIOUR_H

namespace snake::physic {

    class MoveBehaviour {
    public:
        virtual ~MoveBehaviour() = default;

        virtual void moveUp(float dt) = 0;

        virtual void moveDown(float dt) = 0;

        virtual void moveLeft(float dt) = 0;

        virtual void moveRight(float dt) = 0;
    };

}

#endif /* MOVEBEAHVIOUR_H */
