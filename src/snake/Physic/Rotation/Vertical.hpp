#ifndef VERTICAL_H
#define VERTICAL_H

#include <snake/Physic/Rotation/Direction.hpp>

namespace snake::physic {
    
    class Vertical : public Direction {
    public:
        ID getID() const override;
    };

}


#endif /* VERTICAL_H */
