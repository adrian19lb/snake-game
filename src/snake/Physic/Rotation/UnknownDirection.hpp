#ifndef UNKNOWNDIRECTION_H
#define UNKNOWNDIRECTION_H

#include <snake/Physic/Rotation/Direction.hpp>

namespace snake::physic {
    
    class UnknownDirection : public Direction {
    public:
        ID getID() const override;
    };

}

#endif /* UNKNOWNDIRECTION_H */
