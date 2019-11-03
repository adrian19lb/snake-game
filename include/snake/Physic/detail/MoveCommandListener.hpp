#ifndef MOVECOMMANDLISTENER_H
#define MOVECOMMANDLISTENER_H

#include <snake/Physic/Movement/MoveActionMap.hpp>
#include <snake/Physic/Movement/MoveCommand.hpp>
#include <snake/Physic/Movement/MoveCommandFactory.hpp>

namespace snake::physic::detail {
    
    template<typename T>
    class MoveCommandListener {
    public:
        MoveCommandListener(MoveActionMap<T>* actionMap)
        : moveCommandFactory() 
        , currentMoveCommand(moveCommandFactory.createMoveCommand(MoveAction::Unknow))
        , actionMap(actionMap) {
        
        }
        
        template<typename... Args> MoveCommand* listen(bool (*receiver)(T, Args...)) {
            updateCurrentMoveCommandIfMoveActionDetected(receiver);

            return currentMoveCommand;  
        }
    private:
        template<typename... Args> void updateCurrentMoveCommandIfMoveActionDetected(bool (*receiver)(T, Args...)) {
            for (auto&& [moveAction, button] : *actionMap) {
                if (receiver(button)) {
                    currentMoveCommand = moveCommandFactory.createMoveCommand(moveAction);
                    break; 
                } 
            }
        }
    private:
        MoveCommandFactory moveCommandFactory;
        MoveCommand* currentMoveCommand;
        MoveActionMap<T>* actionMap;
    };

}

#endif /* MOVECOMMANDLISTENER_H */
