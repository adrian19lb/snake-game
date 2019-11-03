#ifndef HORIZONTAL_H
#define HORIZONTAL_H

#include <snake/Physic/Rotation/Direction.hpp>

namespace snake::physic {
    
    class Horizontal : public Direction {
    public:
        ID getID() const override;
    };

}


#endif /* HORIZONTAL_H */
