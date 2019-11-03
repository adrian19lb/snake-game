#ifndef NEARTAILBODYEXTENDER_H
#define NEARTAILBODYEXTENDER_H 

#include <snake/Physic/BodyExtender/BodyExtender.hpp>

namespace snake::physic {
    
    class NearTailBodyExtender : public BodyExtender {
    public:
        NearTailBodyExtender(physic::Body* body);

        void extendAt(sf::Vector2f const& position) override;
    protected:
        bool arePrevPhysicComponentCoordEqualWithCreated(SideOffsetCreator&& creator) const override;
    private:
        physic::Body* body;
    };

}

#endif /* ifndef NEARTAILBODYEXTENDER_H */

