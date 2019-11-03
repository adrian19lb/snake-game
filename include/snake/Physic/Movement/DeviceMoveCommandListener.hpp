#ifndef DEVICEMOVECOMMANDLISTENER_H
#define DEVICEMOVECOMMANDLISTENER_H

#include <snake/Physic/Movement/MoveCommand.hpp>

namespace snake::physic {
    
    class DeviceMoveCommandListener {
    public:
        virtual ~DeviceMoveCommandListener() = default;

        virtual MoveCommand* listen() = 0;

        virtual void add(DeviceMoveCommandListener* device) { 
        
        }

        virtual void remove(DeviceMoveCommandListener* device) { 
        
        }
    };


}

#endif /* DEVICECOMMANDLISTENERCOMPOSITE_H */
