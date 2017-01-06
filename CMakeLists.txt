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
        src/HorizontalMover.cxx src/HorizontalMover.hxx
        src/HorizontalMovements.cxx src/HorizontalMovements.hxx
        src/WindowRefGetter.cxx src/WindowRefGetter.hxx
        src/HorizontalMovement.cxx src/HorizontalMovement.hxx
        src/Window.cxx
        src/Window.hxx src/WindowOpener.cxx
        src/WindowOpener.hxx src/GameLooper.cxx
        src/GameLooper.hxx src/WindowRenamer.cxx
        src/WindowRenamer.hxx src/WindowRefGetter.cxx
        src/WindowRefGetter.hxx
        src/BoxDrawer.cxx src/BoxDrawer.hxx
        src/PNGLoader.cxx src/PNGLoader.hxx
        src/PNG.cxx src/PNG.hxx src/PNGDrawer.cxx
        src/PNGDrawer.hxx src/PNGSurfaceGetter.cxx
        src/PNGSurfaceGetter.hxx src/RectBuilder.cxx
        src/RectBuilder.hxx src/DimensionCalculator.cxx
        src/DimensionCalculator.hxx src/Dimension.cxx
        src/Dimension.hxx src/DrawPosition.cxx src/DrawPosition.hxx
        src/WindowUpdater.cxx src/WindowUpdater.hxx
        src/IMGInitializer.cxx src/IMGInitializer.hxx
        src/Vector2D.cxx src/Vector2D.hxx
        src/BackgroundRendererEntityFactory.cxx src/BackgroundRendererEntityFactory.hxx
        src/LoopTerminator.cxx src/LoopTerminator.hxx
        src/StackSetEntityMaker.cxx src/StackSetEntityMaker.hxx
        src/WindowCleaner.cxx src/WindowCleaner.hxx
        src/TerrainRendererSubSystem.cxx src/TerrainRendererSubSystem.hxx
        src/Renderable.hxx src/Renderable.cxx
        src/WindowPositioner.cxx src/WindowPositioner.hxx
        src/PNGFactory.cxx src/PNGFactory.hxx
        src/BackgroundRendererSubSystem.cxx src/BackgroundRendererSubSystem.hxx
        src/BoxRendererSubSystem.hxx src/BoxRendererSubSystem.cxx
        src/SmokeAdder.hxx src/SmokeAdder.cxx
        src/WindowDimensionGetter.cxx src/WindowDimensionGetter.hxx src/EntityFactory.cxx src/BoxDrawingConfiguration.cxx src/BoxDrawingConfiguration.hxx src/EntityFactory.hxx src/RenderingSystem.cxx src/RenderingSystem.hxx src/BackgroundComponent.cxx src/BackgroundComponent.hxx src/GameSystem.cxx src/GameSystem.hxx src/DrawCanvas.cxx src/DrawCanvas.hxx src/Scale.cxx src/Scale.hxx src/GameBeginZoomOut.cxx src/GameBeginZoomOut.hxx src/ZoomOutAnimationSystem.cxx src/ZoomOutAnimationSystem.hxx src/TerrainRenderer.cxx src/TerrainRenderer.hxx src/ResourceUtil.cxx src/ResourceUtil.hxx src/TerrainComponent.cxx src/TerrainComponent.hxx src/MouseClickTracker.cxx src/MouseClickTracker.hxx src/MouseClicked.cxx src/MouseClicked.hxx src/BoxPositionCalculator.cxx src/BoxPositionCalculator.hxx tests/DisapperanceAnimationTests.cxx tests/AnimationSet.cxx tests/AnimationSet.hxx src/RenderingSubSystem.cxx src/RenderingSubSystem.hxx tests/AnimationSubSystem.cxx tests/AnimationSubSystem.hxx tests/AnimationStep.cxx tests/AnimationStep.hxx src/TilePopperSystem.cxx src/TilePopperSystem.hxx src/WillPop.cxx src/WillPop.hxx)

#definitions
add_definitions("-Wall -Wextra -pedantic-errors -Werror=return-type")

# includes/include directories
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_sdl2.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_boost.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_gtest.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_gmock.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_entityx.cmake)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# binaries/executables/libraries
add_library(boxesGame STATIC ${BOXES_GAME_SRC_FILES}  )

# linker
target_link_libraries(boxesGame ${Boost_LIBRARIES} ${SDL2_LIBRARY_SET} ${ENTITYX_BINARIES})

#tests

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)
