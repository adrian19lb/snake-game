#ifndef MOVEMENTCOMMANDSMAPPER_H
#define MOVEMENTCOMMANDSMAPPER_H

#include <snake/Physic/Movement/MoveAction.hpp>
#include <map>
#include <memory>

namespace snake::physic {
    
    class MoveCommand;

    class MoveCommandsMapper {
    public:
        MoveCommandsMapper();

        MoveCommand* get(MoveAction action) const;
    private:
        std::map<MoveAction, std::unique_ptr<MoveCommand>> movementCommandMapper; 
    };

}

#endif /* MOVEMENTCOMMANDSMAPPER_H */
