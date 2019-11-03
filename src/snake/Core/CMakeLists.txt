set(SRCROOT ${PROJECT_SOURCE_DIR}/src/snake/Core)

set(SOURCES
    ${SRCROOT}/EntityComponentSystem/Entity.cpp
    ${SRCROOT}/EntityComponentSystem/Procesor.cpp
    ${SRCROOT}/EntityComponentSystem/World.cpp
    ${SRCROOT}/EntityComponentSystem/Component.cpp
)

snake_add_library(${PROJECT_NAME}_core SOURCES ${SOURCES})

find_package(SFML 2.5.1 COMPONENTS system graphics REQUIRED)

target_link_libraries(${PROJECT_NAME}_core
    PUBLIC
        sfml-system
        sfml-graphics
)
