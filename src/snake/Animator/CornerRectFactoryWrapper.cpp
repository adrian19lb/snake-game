#include <AnimationSystem/TurnRightResponser.hpp>
#include <AnimationSystem/TurnLeftResponser.hpp>
#include <AnimationSystem/CornerRectWrapper.hpp>

namespace snake::render {
        
    CornerRectFactoryWrapper::CornerRectFactoryWrapper(AnimationEvent& event, TextureRectFactory<TextureRectID::Player, int>* factory)
    : event(event)
    , baseCornerFactory( std::make_unique<CornerRectFactory>( std::make_unique<TurnLeftResponser>(), TextureRectID::Player::BottomLeftCorner ) ) {
        baseCornerFactory->setFactory(factory);
        baseCornerFactory->setProxy( createProxyCornerFactory(factory) );
    }

    std::unique_ptr<CornerRectFactory> CornerRectFactoryWrapper::createProxyCornerFactory(TextureRectFactory<TextureRectID::Player, int>* factory) {
        auto proxyFactory = std::make_unique<CornerRectFactory>( std::make_unique<TurnRightResponser>(), TextureRectID::Player::TopLeftCorner);
        proxyFactory->setFactory(factory);

        return proxyFactory;
    }

    sf::IntRect* CornerRectFactoryWrapper::create() {
        return baseCornerFactory->create(event);
    }

}
