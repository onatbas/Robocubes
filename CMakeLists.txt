cmake_minimum_required(VERSION 3.1)
project(boxesGame)
include(CTest)
enable_testing()

# sets
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")
set (CMAKE_CXX_STANDARD 14)
set(BOXES_GAME_SRC_FILES
        src/Colors.hxx
        src/Game.hxx src/Game.cxx
        src/Box.hxx src/Box.cxx
        src/BoxStacker.hxx src/BoxStacker.cxx
        src/Stack.hxx src/Stack.cxx
        src/StackPopper.hxx src/StackPopper.cxx
        src/VerticalNeighbourCounter.hxx src/VerticalNeighbourCounter.cxx
        src/VerticalNeigbourCountResult.hxx src/VerticalNeigbourCountResult.cxx
        src/StackPopResult.hxx src/StackPopResult.cxx
        src/StackDivider.hxx src/StackDivider.cxx
        src/AdjacentNeighbourCounter.hxx src/AdjacentNeighbourCounter.cxx
        src/StackSet.hxx src/StackSet.cxx
        src/BoxPosition.hxx src/BoxPosition.cxx
        src/AdjacentNeighbourCountResult.hxx src/AdjacentNeighbourCountResult.cxx
        src/TileExistsChecker.hxx src/TileExistsChecker.cxx
        src/SameColorChecker.hxx src/SameColorChecker.cxx
        src/NeighboursInVicinityCounter.hxx src/NeighboursInVicinityCounter.cxx
        src/AdjacentPopper.hxx src/AdjacentPopper.cxx
        src/AdjacentPopperResult.hxx src/AdjacentPopperResult.cxx
        src/PoppedPositions.hxx src/PoppedPositions.cxx
        src/VerticalMover.hxx src/VerticalMover.cxx
        src/VerticalMovements.hxx src/VerticalMovements.cxx
        src/VerticalMovement.hxx src/VerticalMovement.cxx
        tests/HorizontalMover.cxx tests/HorizontalMover.hxx
        tests/HorizontalMovements.cxx tests/HorizontalMovements.hxx
        tests/HorizontalMovement.cxx tests/HorizontalMovement.hxx)

#definitions
add_definitions("-Wall -Wextra -pedantic-errors -Werror=return-type")

# includes/include directories
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_sdl2.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_boost.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_gtest.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_gmock.cmake)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# binaries/executables/libraries
add_library(boxesGame STATIC ${BOXES_GAME_SRC_FILES}  )

# linker
target_link_libraries(boxesGame ${Boost_LIBRARIES} ${SDL2_LIBRARY})

#tests
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
