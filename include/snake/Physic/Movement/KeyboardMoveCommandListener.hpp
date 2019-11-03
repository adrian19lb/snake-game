#ifndef KEYBOARDCOMMANDLISTENER_H
#define KEYBOARDCOMMANDLISTENER_H

#include <snake/Physic/Movement/DeviceMoveCommandListener.hpp>
#include <snake/Physic/detail/MoveCommandListener.hpp>
#include <snake/Physic/Movement/MoveActionMap.hpp>
#include <SFML/Window/Keyboard.hpp>

namespace snake::physic {
    
    class KeyboardMoveCommandListener : public DeviceMoveCommandListener {
    public:
        KeyboardMoveCommandListener(); 

        MoveCommand* listen() override;

        MoveActionMap<sf::Keyboard::Key>* getMoveActionMap();
    private:
        MoveActionMap<sf::Keyboard::Key> keyboardActionMap;
        detail::MoveCommandListener<sf::Keyboard::Key> moveCommandListener;
    };

}

#endif /* KEYBOARDCOMMANDLISTENER_H */
