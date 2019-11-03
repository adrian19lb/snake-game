#ifndef ENTITY_H
#define ENTITY_H

#include <snake/Core/EntityComponentSystem/Procesor.hpp>
// #include <snake/Physic/Body.hpp>
#include <set>

template<typename S>
struct enable_make : public S {
    template<typename... T>
    enable_make(T&&... t)
    : S(std::forward<T>(t)...) {

    }
};

namespace snake::core {

    class World;

    using EntityID = unsigned int long;

    struct Entity {
        friend class World;
        friend enable_make<Entity>;

        const EntityID id;

        bool isAlive() const;
        template<typename... ProcesorType> bool has() const;
    private:
        std::set<ProcesorID> procesorsList;
        bool mIsAlive = true;
    private:
        Entity(const EntityID id);
        template<typename... ProcesorTypes> void attach();
        template<typename... ProcesorTypes> void detach();
    };

}

#include <snake/Core/EntityComponentSystem/Entity.inl>

#endif /* ENTITY_H */
