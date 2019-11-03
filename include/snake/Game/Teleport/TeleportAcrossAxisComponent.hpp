#ifndef TELEPORTACROSSAXISCOMPONENT_H
#define TELEPORTACROSSAXISCOMPONENT_H

#include <SFML/System/Vector2.hpp>
#include <snake/Core/EntityComponentSystem/Component.hpp>

namespace snake::game {

    struct TeleportAcrossAxsisComponent : public core::Component<TeleportAcrossAxsisComponent> {
        struct Axis {
            Axis(float value);

            virtual ~Axis() = default;

            virtual sf::Vector2f transform(sf::Vector2f position) const = 0; 
        protected:
            const float value;
        };

        struct X : public Axis {
            X(float dx);

            sf::Vector2f transform(sf::Vector2f position) const override;
        };

        struct Y : public Axis {
            Y(float dy);

            sf::Vector2f transform(sf::Vector2f position) const override;
        };
        
        Axis* axis;
        
        TeleportAcrossAxsisComponent(Axis* axis);

        ~TeleportAcrossAxsisComponent();
    };

}


#endif /* TELEPORTACROSSAXISCOMPONENT_H */
