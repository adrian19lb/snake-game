#ifndef PROCESSORVISITOR_H
#define PROCESSORVISITOR_H

namespace snake::animator {

    class AnimationProcessor;

}

namespace snake::physic {

    class MoveCommandProcessor;
    class MoveBehaviourProcessor;
    class RotationProcessor;
    class CollisionProcessor;

}

namespace snake::renderer {

    class MeshProcesor;

}

namespace snake::core {
    
    class ProcesorVisitor {
    public:
        virtual ~ProcesorVisitor() = default;
        virtual void visit(animator::AnimationProcessor* processor) = 0;
        virtual void visit(renderer::MeshProcesor* processor) = 0;
        virtual void visit(physic::MoveCommandProcessor* processor) = 0;
        virtual void visit(physic::MoveBehaviourProcessor* processor) = 0;
        virtual void visit(physic::RotationProcessor* processor) = 0;
        virtual void visit(physic::CollisionProcessor* processor) = 0;
    };

}

#endif /* PROCESSORVISITOR_H */
