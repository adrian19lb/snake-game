#include <AnimationSystem/MoveForwardResponser.hpp>
#include <AnimationSystem/CornerRectFactory.hpp>
#include <Event/AnimationEvent.hpp>

namespace snake::render {
    
        CornerRectFactory::CornerRectFactory(std::unique_ptr<TurnResponser> turn, TextureRectID::Player rect)
        : rect(rect)
        , turnResponser( std::move(turn) ) {
            
        }

        sf::IntRect* CornerRectFactory::create(AnimationEvent& action) {
            if ( turnResponser->isActive(action.getAction(), action.getPrevAction()) ) {
                return factory->createFlyweight(rect);
            }else {
                return createByProxy(action);
            }
        }

        sf::IntRect* CornerRectFactory::createByProxy(AnimationEvent& event) {
            if (proxy == nullptr) {
                createDefaultProxy();
            }

            return proxy->create(event);
        }

        void CornerRectFactory::createDefaultProxy() {
            proxy = std::make_unique<CornerRectFactory>( std::make_unique<MoveForwardResponser>(), TextureRectID::Player::Torso );
            proxy->setFactory(factory);
        }

        void CornerRectFactory::setProxy(std::unique_ptr<CornerRectFactory> factory) {
            proxy = std::move(factory);
        }

        void CornerRectFactory::setFactory(TextureRectFactory<TextureRectID::Player, int>* factory) {
            this->factory = factory; 
        }

}
