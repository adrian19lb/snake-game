#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <vector>
#include <memory>

namespace snake {
    
    template<typename StatesType>
    class MultiStatesHandler {
    public:
        using iterator = typename::std::vector< std::unique_ptr<StatesType> >::iterator;
        
        MultiStatesHandler() = default;

        template<typename... Args>
        MultiStatesHandler(Args... args) {
            states.emplace_back( std::move(args)... );
        }

        template<typename T, typename... Args> void push(Args&&... args) {
            states.emplace_back( std::make_unique<T>( this, std::forward<Args>(args)... ) ); 
        }

        iterator begin() {
            return states.begin();
        }

        iterator end() {
            return states.end();
        }

        void applyChanges() {
            removeUnrequiredStates();
        }

    private:
        void removeUnrequiredStates() {
            for (auto&& change: pendingList) {
                states.erase( std::remove_if(states.begin(), states.end(), [&change](auto const& itr) {
                    return change == itr.get();         
                })); 
            }
        }

    public:
        void pop(StatesType* state) {
            pendingList.emplace_back(state);
        }

        void clear() {
            states.clear();
        }
    private:
        std::vector< std::unique_ptr<StatesType> > states;
        std::vector<StatesType*> pendingList;
    };

}

#endif /* STATEMANAGER_H */
