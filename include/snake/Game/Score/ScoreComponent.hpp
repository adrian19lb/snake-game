#ifndef SCORECOMPONENT_H
#define SCORECOMPONENT_H

#include <snake/Core/EntityComponentSystem/Component.hpp>

namespace snake::game {

    struct ScoreComponent : public core::Component<ScoreComponent> {
        const int score = 0;

        ScoreComponent(int score)
        : score(score) {
        
        }

    };

}

#endif /* SCORECOMPONENT_H */
