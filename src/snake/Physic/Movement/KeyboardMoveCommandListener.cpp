#include <snake/Physic/Movement/KeyboardMoveCommandListener.hpp>

namespace snake::physic {
        
    KeyboardMoveCommandListener::KeyboardMoveCommandListener() 
    : moveCommandListener(&keyboardActionMap) {
        keyboardActionMap.add(MoveAction::MoveUp, sf::Keyboard::Key::Up);
        keyboardActionMap.add(MoveAction::MoveDown, sf::Keyboard::Key::Down);
        keyboardActionMap.add(MoveAction::MoveLeft, sf::Keyboard::Key::Left);
        keyboardActionMap.add(MoveAction::MoveRight, sf::Keyboard::Key::Right);
    }

    MoveCommand* KeyboardMoveCommandListener::listen() {
        return moveCommandListener.listen(sf::Keyboard::isKeyPressed);
    }

    MoveActionMap<sf::Keyboard::Key>* KeyboardMoveCommandListener::getMoveActionMap() {
        return &keyboardActionMap; 
    }

}
