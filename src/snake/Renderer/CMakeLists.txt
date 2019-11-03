set(SRCROOT ${PROJECT_SOURCE_DIR}/src/snake/Renderer)

set(SOURCES
    ${SRCROOT}/MeshProcessor.cpp
    ${SRCROOT}/Map.cpp
    ${SRCROOT}/TitleCreator.cpp
)
    

snake_add_library(${PROJECT_NAME}_renderer SOURCES ${SOURCES})

find_package(SFML 2.5.1 COMPONENTS graphics REQUIRED)

target_link_libraries(${PROJECT_NAME}_renderer
    PUBLIC
        sfml-graphics
        ${PROJECT_NAME}_eventer;
        ${PROJECT_NAME}_physic
        # ${PROJECT_NAME}_animator
)
