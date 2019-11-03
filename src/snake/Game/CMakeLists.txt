set(INCROOT ${PROJECT_SOURCE_DIR}/include/snake/Game) 
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/snake/Game) 

set(SOURCES 
    ${SRCROOT}/System/System.cpp
    ${SRCROOT}/System/PhysicsSystem.cpp
    ${SRCROOT}/System/GraphicsSystem.cpp
    ${SRCROOT}/Entity/EntityAbstractCreatorImpl.cpp
    ${SRCROOT}/Entity/EntityProcessorsAttacher.cpp
    ${SRCROOT}/Entity/ProcessorsAttacher.cpp
    ${SRCROOT}/Entity/PlayerProcessorsAttacher.cpp
    ${SRCROOT}/Teleport/TeleportAcrossAxsisComponent.cpp
    ${SRCROOT}/Teleport/EntityAcrossAxsisTeleporter.cpp
    ${SRCROOT}/Score/ScoreComputer.cpp
    ${SRCROOT}/Score/ScoredEntityBodyExtender.cpp
    ${SRCROOT}/Score/ScorableEntityRandomPositionMaker.cpp
)

snake_add_library(${PROJECT_NAME}_game SOURCES ${SOURCES})

target_link_libraries(${PROJECT_NAME}_game
    PUBLIC
        ${PROJECT_NAME}_core
        ${PROJECT_NAME}_physic
        ${PROJECT_NAME}_animator
        ${PROJECT_NAME}_renderer
        ${PROJECT_NAME}_debug
)

add_custom_command(TARGET ${PROJECT_NAME}_game PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/doc ${CMAKE_BINARY_DIR}/doc
)

add_custom_command(TARGET ${PROJECT_NAME}_game PRE_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/media ${CMAKE_BINARY_DIR}/media
)
