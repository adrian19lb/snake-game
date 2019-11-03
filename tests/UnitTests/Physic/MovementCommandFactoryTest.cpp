#include <gtest/gtest.h>
#include <snake/Physic/Movement/MoveCommandFactory.hpp>

namespace snake::physic::testing {
    
    TEST(MoveCommandFactoryTest, testCreateMoveCommand) {
        MoveCommandFactory moveCommandFactory;
        
        EXPECT_EQ( moveCommandFactory.createMoveCommand(MoveAction::MoveUp)->getID(), MoveAction::MoveUp);
        EXPECT_EQ( moveCommandFactory.createMoveCommand(MoveAction::MoveUp)->getID(), MoveAction::MoveUp);
        EXPECT_EQ( moveCommandFactory.createMoveCommand(MoveAction::MoveDown)->getID(), MoveAction::MoveUp);
        EXPECT_EQ( moveCommandFactory.createMoveCommand(MoveAction::MoveLeft)->getID(), MoveAction::MoveLeft);
        EXPECT_EQ( moveCommandFactory.createMoveCommand(MoveAction::MoveRight)->getID(), MoveAction::MoveLeft);
    }

}
