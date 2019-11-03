#ifndef COMPONENT_H
#define COMPONENT_H

namespace  snake::core {
    
    using ComponentID = unsigned int long;
    
    class BaseComponent {
    public:
        virtual ~BaseComponent() = default;
    protected:
        static ComponentID ID;
    };

    template<typename ComponentType>
    class Component : public BaseComponent {
    public:
        virtual ~Component() = default;
        static ComponentID getID() { return ID; }
    private:
        static ComponentID ID;
    };
    
    template<typename ComponentType>
    ComponentID Component<ComponentType>::ID = BaseComponent::ID++;

}

#endif /* COMPONENT_H */
