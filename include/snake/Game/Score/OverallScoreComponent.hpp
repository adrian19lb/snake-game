#ifndef OVERALLSCORECOMPONENT_H
#define OVERALLSCORECOMPONENT_H

#include <snake/Core/EntityComponentSystem/Component.hpp>

namespace snake::game {

    struct OverallScoreComponent : public core::Component<OverallScoreComponent> {
        int value = 0; 
    };

}

#endif /* OVERALLSCORECOMPONENT_H */
