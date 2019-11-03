#ifndef BODYEXTENDER_H
#define BODYEXTENDER_H

#include <snake/Physic/BodyExtender/SideOffsetCreator.hpp>
#include <snake/Physic/Body.hpp>

namespace snake::physic {
    
    class BodyExtender {
    public:
        BodyExtender(Body* body);
        
        virtual ~BodyExtender() = default;

        void extendFrom(SideOffsetCreator&& creator);
    protected:
        virtual bool arePrevPhysicComponentCoordEqualWithCreated(SideOffsetCreator&& creator) const = 0;
    protected:
        virtual void extendAt(sf::Vector2f const& position) = 0;
    private:
        Body* body; 
    };

}

#endif /* BODYEXTENDER_H */
