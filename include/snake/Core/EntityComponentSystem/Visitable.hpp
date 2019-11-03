#ifndef VISITABLEENTITYLOGICCOMPONENT_H
#define VISITABLEENTITYLOGICCOMPONENT_H

#include <memory>

namespace snake::core {
    
    struct Entity;
    class ProcesorVisitor;
    
    class Visitable {
    public:
        virtual ~Visitable() = default;
        virtual void enter(ProcesorVisitor* visitor) = 0;
    };

}

#endif /* VISITABLEENTITYLOGICCOMPONENT_H */
