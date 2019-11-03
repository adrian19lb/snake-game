#include <snake/Animator/States/AnimationState.hpp>

namespace snake::animator {

    AnimationState::AnimationState(MultiStatesHandler<AnimationState>* stateManager)
    : stateManager(stateManager) {
    
    }

}
