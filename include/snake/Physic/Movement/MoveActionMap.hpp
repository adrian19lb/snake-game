#ifndef MOVEACTIONMAP_H
#define MOVEACTIONMAP_H

#include <snake/Physic/Movement/MoveAction.hpp>
#include <map>

namespace snake::physic {
    
    template<typename T>
    class MoveActionMap {
    public:
        using iterator = typename std::map<MoveAction, T>::iterator;
    public:
        iterator begin() {
            return actionMap.begin();
        } 

        iterator end() {
            return actionMap.end();
        }

        void add(MoveAction action,T button) {
            actionMap[action] = button; 
        }

        void remove(MoveAction action) {
            actionMap.erase(action); 
        }

        T const& get(MoveAction action) const {
            return actionMap.at(action);
        }
    private:
        std::map<MoveAction, T> actionMap;
    };

}


#endif /* MOVEACTIONMAP_H */
