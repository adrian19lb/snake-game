#ifndef RIGHTSIDEOFFSETCREATOR_H
#define RIGHTSIDEOFFSETCREATOR_H

#include <snake/Physic/BodyExtender/SideOffsetCreator.hpp>

namespace snake::physic {
    
    class RightSideOffsetCreator : public SideOffsetCreator {
    public:
        RightSideOffsetCreator(PhysicComponent* segment);

        sf::Vector2f createOffset() const override;
    };

}

#endif /* RIGHTSIDEOFFSETCREATOR_H */
