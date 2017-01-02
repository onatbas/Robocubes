cmake_minimum_required(VERSION 3.1)
project(boxesGame)
include(CTest)
enable_testing()

# sets
set (CMAKE_CXX_STANDARD 14)
set(BOXES_GAME_HDR_FILES src/Game.hxx src/Box.hxx src/BoxStacker.hxx src/Stack.hxx src/StackPopper.hxx src/VerticalNeighbourCounter.hxx src/VerticalNeigbourCountResult.hxx src/StackPopResult.hxx src/StackDivider.hxx src/AdjacentNeighbourCounter.hxx src/StackSet.hxx src/BoxPosition.hxx src/AdjacentNeighbourCountResult.hxx src/TileExistsChecker.hxx src/SameColorChecker.hxx src/NeighboursInVicinityCounter.hxx src/AdjacentPopper.hxx src/AdjacentPopperResult.hxx src/PoppedPositions.hxx src/VerticalMover.hxx src/VerticalMovements.hxx src/VerticalMovement.hxx )
set(BOXES_GAME_SRC_FILES src/Game.cxx src/Box.cxx src/BoxStacker.cxx src/Stack.cxx src/StackPopper.cxx src/VerticalNeighbourCounter.cxx src/VerticalNeigbourCountResult.cxx src/StackPopResult.cxx src/StackDivider.cxx src/AdjacentNeighbourCounter.cxx src/StackSet.cxx src/BoxPosition.cxx src/AdjacentNeighbourCountResult.cxx src/TileExistsChecker.cxx src/SameColorChecker.cxx src/NeighboursInVicinityCounter.cxx src/AdjacentPopper.cxx src/AdjacentPopperResult.cxx src/PoppedPositions.cxx src/VerticalMover.cxx src/VerticalMovements.cxx src/VerticalMovement.cxx )

#definitions
add_definitions("-Wall -Wextra -pedantic-errors -Werror=return-type")

# includes/include directories
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_boost.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_gtest.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_gmock.cmake)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# binaries/executables/libraries
add_library(boxesGame STATIC ${BOXES_GAME_HDR_FILES} ${BOXES_GAME_SRC_FILES}  )

# linker
target_link_libraries(boxesGame ${Boost_LIBRARIES} )

#tests
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)