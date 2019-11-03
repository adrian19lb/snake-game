set(SRCROOT ${PROJECT_SOURCE_DIR}/src/snake/Animator)

set(SOURCES
    ${SRCROOT}/AnimationMemento.cpp
    ${SRCROOT}/BodyStatesAnimator.cpp
    ${SRCROOT}/NullAnimationMemento.cpp
    ${SRCROOT}/Recorder.cpp
    ${SRCROOT}/States/AnimationState.cpp
    ${SRCROOT}/States/BodyAnimationState.cpp
    ${SRCROOT}/States/HeadAnimationState.cpp
    ${SRCROOT}/States/SpecificPositionAnimationState.cpp
    ${SRCROOT}/States/TailAnimationState.cpp
    ${SRCROOT}/TextureRectMapper.cpp
    ${SRCROOT}/AnimationProcessor.cpp
)

snake_add_library(${PROJECT_NAME}_animator SOURCES ${SOURCES})

find_package(SFML 2.5.1 COMPONENTS graphics REQUIRED)

target_link_libraries(${PROJECT_NAME}_animator
    PUBLIC
        sfml-graphics
        ${PROJECT_NAME}_eventer;
        ${PROJECT_NAME}_physic
)
