#include <gtest/gtest.h>
#include <snake/Physic/Movement/KeyboardMoveCommandListener.hpp>

namespace snake::physic::testing {
    
    TEST(KeyboardMoveCommandListenerTest, testListenMoveCommand) {
        KeyboardMoveCommandListener keyboard;
        
        std::cerr << "[          ] Press ESC to end test\n";
        while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            auto moveCommand = keyboard.listen();
            switch (moveCommand->getID()) {
                case MoveAction::MoveUp:
                    std::cerr << "MoveAction::MoveUp\n";
                    break;
                case MoveAction::MoveDown:
                    std::cerr << "MoveAction::MoveDown\n";
                    break;
                case MoveAction::MoveLeft:
                    std::cerr << "MoveAction::MoveLeft\n";
                    break;
                case MoveAction::MoveRight:
                    std::cerr << "MoveAction::MoveRight\n";
                    break;
                case MoveAction::Unknow:
                    std::cerr << "MoveAction::Unknow\n";
                    break;
            }
        }
    }
}
