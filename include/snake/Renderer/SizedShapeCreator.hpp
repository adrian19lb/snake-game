#ifndef SIZEDSHAPECREATOR_H
#define SIZEDSHAPECREATOR_H

#include <memory>
#include <snake/Renderer/PhysicComponentScaler.hpp>

namespace sf {
    class Shape;
}

namespace snake::renderer {
    
    template<typename ShapeType>
    class SizedShapeModelCreator {
    public:
        SizedShapeModelCreator(physic::PhysicComponent* componet, float scale)
        : scaler(componet, scale) {
        
        }

        template<typename... Args> std::unique_ptr<sf::Shape> create(Args... args) {
            auto shapeSize = scaler.scaleSize();
            auto createdShape = std::make_unique<ShapeType>(shapeSize, std::forward<Args>(args)... );
            createdShape->setPosition( scaler.scalePosition() );

            return std::move(createdShape);
        }
    private:
        PhysicComponentScaler<ShapeType> scaler;
    };

}


#endif /* SIZEDSHAPECREATOR_H */
