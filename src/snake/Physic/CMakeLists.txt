set(SRCROOT ${PROJECT_SOURCE_DIR}/src/snake/Physic)

set(SOURCES
    ${SRCROOT}/Body.cpp
    ${SRCROOT}/PhysicComponent.cpp
    ${SRCROOT}/BodyExtender/SideOffsetCreator.cpp
    ${SRCROOT}/BodyExtender/LeftSideOffsetCreator.cpp
    ${SRCROOT}/BodyExtender/RightSideOffsetCreator.cpp
    ${SRCROOT}/BodyExtender/UpSideOffsetCreator.cpp
    ${SRCROOT}/BodyExtender/DownSideOffsetCreator.cpp
    ${SRCROOT}/BodyExtender/BodyExtender.cpp
    ${SRCROOT}/BodyExtender/NearHeadBodyExtender.cpp
    ${SRCROOT}/BodyExtender/NearTailBodyExtender.cpp
    ${SRCROOT}/Rotation/Direction.cpp
    ${SRCROOT}/Rotation/Vertical.cpp
    ${SRCROOT}/Rotation/Horizontal.cpp
    ${SRCROOT}/Rotation/UnknownDirection.cpp
    ${SRCROOT}/Rotation/OrthogonalDirectionResponser.cpp
    ${SRCROOT}/Rotation/BodyHeadRotator.cpp
    ${SRCROOT}/Rotation/BodyHeadDetachedRotator.cpp
    ${SRCROOT}/Rotation/RotationProcessor.cpp
    ${SRCROOT}/Movement/DirectionResponser.cpp
    ${SRCROOT}/Movement/WormMoveBehaviour.cpp
    ${SRCROOT}/Movement/HorizontalDirectionDetector.cpp
    ${SRCROOT}/Movement/VerticalDirectionDetector.cpp
    ${SRCROOT}/Movement/UnknowDirectionDetector.cpp
    ${SRCROOT}/Movement/MoveCommandFactory.cpp
    ${SRCROOT}/Movement/MoveCommandsMapper.cpp
    ${SRCROOT}/Movement/MoveState.cpp
    ${SRCROOT}/Movement/MoveDownState.cpp
    ${SRCROOT}/Movement/MoveUpState.cpp
    ${SRCROOT}/Movement/MoveLeftState.cpp
    ${SRCROOT}/Movement/MoveRightState.cpp
    ${SRCROOT}/Movement/NullMoveState.cpp
    ${SRCROOT}/Movement/MoveDownCommand.cpp
    ${SRCROOT}/Movement/MoveUpCommand.cpp
    ${SRCROOT}/Movement/NullMoveCommand.cpp
    ${SRCROOT}/Movement/MoveLeftCommand.cpp
    ${SRCROOT}/Movement/MoveRightCommand.cpp
    ${SRCROOT}/Movement/MoveStateFactory.cpp
    ${SRCROOT}/Movement/MoveCommandsProcessor.cpp
    ${SRCROOT}/Movement/MoveBehaviourProcessor.cpp
    ${SRCROOT}/Movement/KeyboardMoveCommandListener.cpp
    ${SRCROOT}/Collision/BodyCollisionDetector.cpp
)

snake_add_library(${PROJECT_NAME}_physic SOURCES ${SOURCES})

find_package(SFML 2.5.1 COMPONENTS system window REQUIRED)

target_link_libraries(${PROJECT_NAME}_physic
    PUBLIC
        sfml-system
        sfml-window
        ${PROJECT_NAME}_eventer
        ${PROJECT_NAME}_core
)
