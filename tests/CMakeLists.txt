add_subdirectory("${PROJECT_SOURCE_DIR}/third_party/googletest" "third_party/googletest")

mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

#Add IDEs support folder clear
set_target_properties(gtest PROPERTIES FOLDER third_party)
set_target_properties(gtest_main PROPERTIES FOLDER third_party)
set_target_properties(gmock PROPERTIES FOLDER third_party)
set_target_properties(gmock_main PROPERTIES FOLDER third_party)

macro(package_add_test TESTNAME TESTED_LIB)
    add_executable(${TESTNAME} ${ARGN})
    target_include_directories(${TESTNAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
    target_include_directories(${TESTNAME} PRIVATE ${PROJECT_SOURCE_DIR}/tests)
    target_link_libraries(${TESTNAME} PRIVATE
        gtest gmock gtest_main pthread ${TESTED_LIB}
    )
    add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})
    set_target_properties(${TESTNAME} PROPERTIES FOLDER tests)
endmacro()

#Animator module tests
package_add_test(AnimatorTest ${PROJECT_NAME}_animator
    UnitTests/Animator/BodyStateAnimatorTest.cpp
)

#Physic module tests
package_add_test(PhysicTest ${PROJECT_NAME}_physic
    UnitTests/Physic/NearHeadBodyExtender.cpp
    UnitTests/Physic/NearTailBodyExtender.cpp
    UnitTests/Physic/WormMoveBehaviourTest.cpp
    UnitTests/Physic/BodyHeadRotatorTest.cpp
    UnitTests/Physic/MovementCommandFactoryTest.cpp
    UnitTests/Physic/MoveCommandListenerTest.cpp
    UnitTests/Physic/BodyCollisionDetectorTest.cpp
)

#Debug module tests
package_add_test(DebugTest ${PROJECT_NAME}_debug
    IntegrationTests/Debug/DebugDrawTest.cpp)

#Core module tests
package_add_test(CoreTest ${PROJECT_NAME}_core
    UnitTests/Core/WorldTest.cpp
    UnitTests/Core/DefaultComponentsCreatorTest.cpp    
)

#Eventer module tests
package_add_test(EventerTest ${PROJECT_NAME}_eventer
    UnitTests/Eventer/EventManagerTest.cpp
)

#Game module tests
package_add_test(GameTest ${PROJECT_NAME}_game
    IntegrationTests/Game/SpecificCollisionTypeNotifierIntegrationTest.cpp
)
