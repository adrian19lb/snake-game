#include <snake/Physic/Movement/MoveCommandsMapper.hpp>
#include <snake/Physic/Movement/MoveUpCommand.hpp>
#include <snake/Physic/Movement/MoveDownCommand.hpp>
#include <snake/Physic/Movement/MoveLeftCommand.hpp>
#include <snake/Physic/Movement/MoveRightCommand.hpp>
#include <snake/Physic/Movement/NullMoveCommand.hpp>

namespace snake::physic {
        
    MoveCommandsMapper::MoveCommandsMapper() {
        movementCommandMapper.emplace( std::make_pair(MoveAction::MoveUp, std::make_unique<MoveUpCommand>()) );
        movementCommandMapper.emplace( std::make_pair(MoveAction::MoveDown, std::make_unique<MoveDownCommand>()) );
        movementCommandMapper.emplace( std::make_pair(MoveAction::MoveLeft, std::make_unique<MoveLeftCommand>()) );
        movementCommandMapper.emplace( std::make_pair(MoveAction::MoveRight, std::make_unique<MoveRightCommand>()) );
        movementCommandMapper.emplace( std::make_pair(MoveAction::Unknow, std::make_unique<NullMoveCommand>()) );
    }

    MoveCommand* MoveCommandsMapper::get(MoveAction action) const {
        return movementCommandMapper.at(action).get();
    }



}
