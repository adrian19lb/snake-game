#ifndef NEARHEADBODYEXTENDER_H
#define NEARHEADBODYEXTENDER_H

#include <snake/Physic/BodyExtender/BodyExtender.hpp>

namespace snake::physic {
    
    class NearHeadBodyExtender : public BodyExtender {
    public:
        NearHeadBodyExtender(physic::Body* body);

        void extendAt(sf::Vector2f const& position) override;
    protected:
        bool arePrevPhysicComponentCoordEqualWithCreated(SideOffsetCreator&& creator) const override;
    private:
        physic::Body* body;
    };

}

#endif /* NEARHEADBODYEXTENDER_H */
