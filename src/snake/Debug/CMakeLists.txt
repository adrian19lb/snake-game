set(SRCROOT ${PROJECT_SOURCE_DIR}/src/snake/Debug)

set(SOURCES
    ${SRCROOT}/imgui_demo.cpp
    ${SRCROOT}/DebugDraw.cpp
    ${SRCROOT}/PlayerPhysicWidget.cpp
)

snake_add_library(${PROJECT_NAME}_debug SOURCES ${SOURCES})

find_package(SFML 2.5.1 COMPONENTS system REQUIRED)

find_package(ImGui-SFML REQUIRED)

target_link_libraries(${PROJECT_NAME}_debug
    PUBLIC
        ${PROJECT_NAME}_game
        ImGui-SFML::ImGui-SFML
)
