#ifndef SIDEOFFSETCREATOR_H
#define SIDEOFFSETCREATOR_H

#include <snake/Physic/PhysicComponent.hpp>
#include <snake/Physic/BodyExtender/OffsetCreator.hpp>

namespace snake::physic {
    
    class SideOffsetCreator : public OffsetCreator {
    public:
        SideOffsetCreator(PhysicComponent* component);
        PhysicComponent* getOffsetedPhysicComponent() const;
        sf::Vector2f createOffsetedPosition() const;
        virtual ~SideOffsetCreator() = default;
    protected:
        sf::Vector2f const& getPhysicComponentSize() const;
        virtual sf::Vector2f createOffset() const  override = 0;
    private:
        physic::PhysicComponent* component;
    };

}

#endif /* SIDEOFFSETCREATOR_H */
