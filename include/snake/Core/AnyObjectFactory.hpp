#ifndef ANYOBJECTFACTORY_H
#define ANYOBJECTFACTORY_H

#include <map>
#include <any>

namespace snake::core {
    
    template<typename Key> 
    class AnyObjectFactory {
    public:
        void remove(Key id) {
            if (auto found = resources.find(id); found != resources.end()) {
                resources.erase(found);
            }
        }

        template<typename Functor> void add(Key id, Functor&& functor) {
            resources.emplace( std::make_pair(id, std::any(functor) ));
        }

        template<typename T> T create(Key id) {
            return std::any_cast<T>( resources.at(id) ); 
        }
    private:
        std::map<Key, std::any> resources;
    };



}

#endif /* ANYOBJECTFACTORY_H */
