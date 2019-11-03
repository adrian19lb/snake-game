#ifndef DOWNSIDEOFFSETCREATOR_H
#define DOWNSIDEOFFSETCREATOR_H

#include <snake/Physic/BodyExtender/SideOffsetCreator.hpp>

namespace snake::physic {
    
    class DownSideOffsetCreator : public SideOffsetCreator {
    public:
        DownSideOffsetCreator(PhysicComponent* segment);

        sf::Vector2f createOffset() const override;
    };

}

#endif /* DOWNSIDEOFFSETCREATOR_H */
