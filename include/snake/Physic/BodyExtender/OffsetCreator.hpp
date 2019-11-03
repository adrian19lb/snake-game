#ifndef OFFSETCREATOR_H
#define OFFSETCREATOR_H

#include <SFML/System/Vector2.hpp>

namespace snake::physic {
    
    class OffsetCreator {
    public:
        virtual ~OffsetCreator() = default;
        virtual sf::Vector2f createOffset() const  = 0;
    };

}

#endif /* OFFSETCREATOR_H */
