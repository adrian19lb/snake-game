#include <AnimationSystem/TurnLeftResponser.cpp>
#include <AnimationSystem/TurnRightResponser.hpp>
#include <AnimationSystem/CornerRectFactoryOrthogonalBuilder.hpp>

namespace snake::render {
    
    CornerRectFactoryOrthogonalBuilder::CornerRectFactoryOrthogonalBuilder(TextureRectFactory<TextureRectID::Player, int>* texRectFactory)
        : texRectFactory(texRectFactory) {
        
    }

    void CornerRectFactoryOrthogonalBuilder::setCornerRectFactoryProxy() {
        proxy = std::make_unique<CornerRectFactory>( std::make_unique<TurnRightResponser>(), textureRectIDProxy);
        proxy->setFactory(texRectFactory);
    }

    void CornerRectFactoryOrthogonalBuilder::setTextureRectIDBase()  {
        textureRectIDBase = TextureRectID::Player::BottomLeftCorner;
    }

    void CornerRectFactoryOrthogonalBuilder::setTextureRectIDProxy()  {
        textureRectIDProxy = TextureRectID::Player::TopLeftCorner;
    }

    std::unique_ptr<CornerRectFactory> CornerRectFactoryOrthogonalBuilder::create()  {
        auto createdFactory = std::make_unique<CornerRectFactory>(std::make_unique<TurnLeftResponser>(), textureRectIDBase);
        createdFactory->setFactory(texRectFactory);
        createdFactory->setProxy( std::move(proxy) );

        return createdFactory;

    }

}
