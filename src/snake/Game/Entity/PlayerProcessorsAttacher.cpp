#include <iostream>
#include <snake/Physic/Movement/KeyboardMoveCommandListener.hpp>
#include <snake/Physic/Movement/WormMoveBehaviour.hpp>
#include <snake/Physic/Rotation/BodyDetachedHeadRotator.hpp>
#include <snake/Animator/BodyStatesAnimator.hpp>
#include <snake/Animator/States/BodyAnimationState.hpp>
#include <snake/Animator/States/HeadAnimationState.hpp>
#include <snake/Animator/States/TailAnimationState.hpp>
#include <snake/Renderer/ShapeModel.hpp>
#include <snake/Game/Teleport/CollisionTeleportComponentNotifier.hpp>
#include <snake/Game/Score/CollisionScoreComponentNotifier.hpp>
#include <snake/Game/Entity/PlayerProcessorsAttacher.hpp>

namespace snake::game {

    PlayerProcessorsAttacher::PlayerProcessorsAttacher(core::ComponentsManager* manager, animator::TextureRectFactory<animator::TextureRect, int>* textFactory)
    : ProcessorsAttacher(manager)
    , textFactory(textFactory) {
        
    }
        
    void PlayerProcessorsAttacher::visit(animator::AnimationProcessor* procesor) {
        animator::AnimationProcessor::value_type functor = [this](const core::Entity* entity) { 
            return tryCreateAnimator(entity); 
        };

        ProcessorsAttacher::add(procesor->getID(), functor);
    }
        
    std::unique_ptr<animator::Animator> PlayerProcessorsAttacher::tryCreateAnimator(const core::Entity* entity) {
        auto body = ProcessorsAttacher::pull<physic::Body>(entity);
        try {
            auto animator = std::make_unique<animator::BodyStateAnimator>(body, *textFactory->create(animator::TextureRect::Head));
            animator->push<animator::BodyAnimationState>(body, textFactory->create(animator::TextureRect::Body));
            animator->push<animator::TailAnimationState>(body, textFactory->create(animator::TextureRect::Tail));
            animator->push<animator::HeadAnimationState>(body, textFactory->create(animator::TextureRect::Head));
            return animator;
                
         }catch(std::out_of_range const& e) {
            std::cerr << "PlayerProcessorsAttacher::visit(animator::AnimationProcessor*)" << e.what() << std::endl;
            auto animator = std::make_unique<animator::BodyStateAnimator>(body, sf::IntRect());
            return animator;
         }
    }

    void PlayerProcessorsAttacher::visit(renderer::MeshProcesor* procesor) {
        renderer::MeshProcesor::value_type functor = [](physic::Body* body, float scale) { 
            return std::make_unique< renderer::ShapeModel<sf::RectangleShape> >(body, scale); 
        };
            
        ProcessorsAttacher::add(procesor->getID(), functor);
        
    }
    
    void PlayerProcessorsAttacher::visit(physic::MoveCommandProcessor* procesor) {
        physic::MoveCommandProcessor::value_type functor = []() { 
            return std::make_unique<physic::KeyboardMoveCommandListener>();
        };

        ProcessorsAttacher::add(procesor->getID(), functor);
    }
    
    void PlayerProcessorsAttacher::visit(physic::MoveBehaviourProcessor* procesor) {
        physic::MoveBehaviourProcessor::value_type functor = [this](const core::Entity* entity) { 
            auto body = ProcessorsAttacher::pull<physic::Body>(entity);
            return std::make_unique<physic::WormMoveBehaviour>(body);
        };

        ProcessorsAttacher::add(procesor->getID(), functor);
    }
    
    void PlayerProcessorsAttacher::visit(physic::RotationProcessor* procesor) {
        physic::RotationProcessor::value_type functor = [this](const core::Entity* entity) { 
            auto body = ProcessorsAttacher::pull<physic::Body>(entity);
            return std::make_unique<physic::BodyDetachedHeadRotator>(body);
        };

        ProcessorsAttacher::add(procesor->getID(), functor);
    }
    
    void PlayerProcessorsAttacher::visit(physic::CollisionProcessor* processor) {
        physic::CollisionProcessor::value_type functor = [processor](core::Entity *const entity) { 
            processor->add<CollisionScoreComponentNotifier>(entity);
            processor->add<CollisionTeleportComponentNotifier>(entity);
        };

        ProcessorsAttacher::add(processor->getID(), functor);
    }

}
