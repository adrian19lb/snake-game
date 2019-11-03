#ifndef DIRECTIONRESPONSER_H
#define DIRECTIONRESPONSER_H

#include <memory>

namespace snake::physic {
    
    class Direction;    

    class DirectionResponser {
    public:
        virtual ~DirectionResponser() = default;
        virtual std::unique_ptr<Direction> response() const = 0; 
    };
}


#endif /* DIRECTIONRESPONSER_H */
