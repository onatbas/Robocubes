cmake_minimum_required(VERSION 3.1)

set(BOXES_GAME_TEST_DEPENDENCIES boxesGame ${GTEST_BOTH_LIBRARIES} ${GMOCK_BOTH_LIBRARIES} ${SDL2_LIBRARY})
set(BOXES_GAME_TEST_HEADERS StackHelpers.hxx)

macro(ADD_NEW_TEST TEST_SOURCE FOLDER_NAME)
    set(TARGET_NAME ${TEST_SOURCE}_TESTTARGET)
    add_executable(${TARGET_NAME} ${TEST_SOURCE}.cxx ${BOXES_GAME_TEST_HEADERS})
    target_link_libraries(${TARGET_NAME} ${BOXES_GAME_TEST_DEPENDENCIES})
    add_test(NAME ${TEST_SOURCE} COMMAND ${TARGET_NAME})
    set_property(TARGET ${TARGET_NAME} PROPERTY FOLDER ${FOLDER_NAME})
endmacro()

# set(MATERIALS_FOLDER ${CMAKE_CURRENT_BINARY_DIR}/boxesGame_tests_materials/)
# file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/materials/ DESTINATION ${MATERIALS_FOLDER})
# add_definitions(-DMATERIALS_FOLDER="${MATERIALS_FOLDER}")

ADD_NEW_TEST(BoxTests "boxesGame_tests")
ADD_NEW_TEST(BoxDisapperanceTest "boxesGame_tests")
ADD_NEW_TEST(VerticalNeighbourCountingTests "boxesGame_tests")
ADD_NEW_TEST(AdjacentNeighbourCountingTests "boxesGame_tests")
ADD_NEW_TEST(AdjacentPopperTests "boxesGame_tests")
ADD_NEW_TEST(VerticalMoveInstructionTests "boxesGame_tests")
ADD_NEW_TEST(HorizontalMoveInstructionTests "boxesGame_tests")

