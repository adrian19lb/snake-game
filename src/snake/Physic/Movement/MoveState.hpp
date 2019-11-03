#ifndef MOVESTATE_H
#define MOVESTATE_H

#include <snake/Physic/Movement/MoveAction.hpp>
#include <snake/Physic/Movement/MoveCommandsMapper.hpp>
#include <snake/Physic/Movement/MoveCommand.hpp>

namespace snake::physic {
    
    class ChangedDirectionDetector;

    class MoveState {
    protected:
        using ChangedDirectionDetectorUPtr = std::unique_ptr<ChangedDirectionDetector>;
    public:
        MoveState(ChangedDirectionDetectorUPtr directionChangeDetector, MoveAction lastAction);

        virtual ~MoveState() = default;
        
        MoveCommand* createMoveCommand() const;
    protected:
        virtual MoveAction getActionID() const = 0;
    private:
        ChangedDirectionDetectorUPtr directionChangeDetector;
        MoveCommandsMapper mapper;
        MoveAction lastAction;
    };
        
    using MoveStateUPtr = std::unique_ptr<MoveState>;     

}

#endif /* MOVESTATE_H */
