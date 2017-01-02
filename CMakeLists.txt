cmake_minimum_required(VERSION 3.1)
project(boxesGame)
include(CTest)
enable_testing()

# sets
set (CMAKE_CXX_STANDARD 14)

add_definitions("-Wall -Wextra -pedantic-errors -Werror=return-type")

set(CLASS_NAMES
        Game
        Box
        BoxStacker
        Stack
        StackPopper
        VerticalNeighbourCounter
        VerticalNeigbourCountResult
        StackPopResult
        StackDivider
        HorizontalAndVerticalNeigbourCounter
        StackSet
        BoxPosition
        HorizontalAndVerticalNeighbourCountResult)

set(BOXES_GAME_HDR_FILES "" include/boxesGame/Colors.hxx)
set(BOXES_GAME_SRC_FILES "")

FOREACH(CLASS_NAME ${CLASS_NAMES})
     set(BOXES_GAME_HDR_FILES
     	${BOXES_GAME_HDR_FILES} ${CMAKE_CURRENT_SOURCE_DIR}/include/boxesGame/${CLASS_NAME}.hxx)
     set(BOXES_GAME_SRC_FILES 
     	${BOXES_GAME_SRC_FILES} ${CMAKE_CURRENT_SOURCE_DIR}/src/${CLASS_NAME}.cxx src/Box.cxx)
ENDFOREACH()

# includes/include directories
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_boost.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_gtest.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_gmock.cmake)
#include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_qt5.cmake)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/boxesGame)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# binaries/executables/libraries
add_library(boxesGame STATIC ${BOXES_GAME_HDR_FILES} ${BOXES_GAME_SRC_FILES}  )

# linker
target_link_libraries(boxesGame ${Boost_LIBRARIES} ${QT5_LINK_TARGETS} )

#tests
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)

#install
install(TARGETS boxesGame DESTINATION ${CMAKE_INSTALL_PREFIX}/bin)
install(FILES ${BOXES_GAME_HDR_FILES} DESTINATION ${CMAKE_INSTALL_PREFIX}/include/boxesGame)
############################################################################################################