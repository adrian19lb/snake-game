#ifndef UPSIDEOFFSETCREATOR_H
#define UPSIDEOFFSETCREATOR_H

#include <snake/Physic/BodyExtender/SideOffsetCreator.hpp>

namespace snake::physic {
    
    class UpSideOffsetCreator : public SideOffsetCreator {
    public:
        UpSideOffsetCreator(PhysicComponent* segment);

        sf::Vector2f createOffset() const override;
    };

}

#endif /* UPSIDEOFFSETCREATOR_H */
