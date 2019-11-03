set(SRCROOT ${PROJECT_SOURCE_DIR}/src/snake/Eventer)

set(SOURCES
    ${SRCROOT}/BaseEvent.cpp
    ${SRCROOT}/BaseReceiver.cpp
)

snake_add_library(${PROJECT_NAME}_eventer SOURCES ${SOURCES})
