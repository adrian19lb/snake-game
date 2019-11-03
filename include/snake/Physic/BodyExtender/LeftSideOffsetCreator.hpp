#ifndef LEFTSIDEOFFSETCREATOR_H
#define LEFTSIDEOFFSETCREATOR_H

#include <snake/Physic/BodyExtender/SideOffsetCreator.hpp>

namespace snake::physic {
    
    class LeftSideOffsetCreator : public SideOffsetCreator {
    public:
        LeftSideOffsetCreator(PhysicComponent* segment);
        sf::Vector2f createOffset() const override;
    };

}

#endif /* LEFTSIDEOFFSETCREATOR_H */
