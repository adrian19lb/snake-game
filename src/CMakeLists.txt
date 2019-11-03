include(${PROJECT_SOURCE_DIR}/cmake/Macros.cmake)

add_subdirectory(snake)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCE_DIR}/app.cpp
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES LINKER_LANGUAGE CXX
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
)



target_link_libraries(${PROJECT_NAME}
    PUBLIC
        ${PROJECT_NAME}_game
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${INCROOT}>
        $<INSTALL_INTERFACE:include/snake>
    PRIVATE
        ${SRCROOT}
)

install(TARGETS ${PROJECT_NAME} EXPORT "${PROJECT_NAME}Config"
    ARCHIVE  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY  DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME  DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(EXPORT "${PROJECT_NAME}Config" DESTINATION share/${PROJECT_NAME}/cmake)

export(TARGETS ${PROJECT_NAME} FILE "${PROJECT_NAME}Config.cmake")
