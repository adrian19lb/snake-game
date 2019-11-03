#include <algorithm>

namespace snake::core {
    
    typedef unsigned int long ProcesorID;

    template<typename... ComponentType> bool Entity::has() const {
        std::set<ProcesorID> subset{ ComponentType::getID()... };
        
        auto functor = [this](auto itr) {
            return procesorsList.find(itr) != procesorsList.end();
        };

        return (subset.size() <= procesorsList.size() ) && ( std::all_of(subset.begin(), subset.end(), functor) );
    }

    template<typename... ComponentTypes> void Entity::attach() { 
        ( procesorsList.emplace( ComponentTypes::getID() ), ... );
    }
    
    template<typename... ComponentTypes> void Entity::detach() {
        ( procesorsList.erase( ComponentTypes::getID() ), ... );
    }

}
