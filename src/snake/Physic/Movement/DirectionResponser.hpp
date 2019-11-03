#ifndef DIRECTIONRESPONSER_H
#define DIRECTIONRESPONSER_H

#include <snake/Physic/Movement/MoveAction.hpp>

namespace snake::physic {
    
    class DirectionResponser {
    public:
       DirectionResponser(MoveAction movementAction);

       bool isVertical() const;

       bool isHorizontal() const;

       bool existAction() const;
    private:
       MoveAction movementAction;
    };


}

#endif /* DIRECTIONRESPONSER_H */
