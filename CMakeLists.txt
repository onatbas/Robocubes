cmake_minimum_required(VERSION 3.1)
project(boxesGame)
include(CTest)
enable_testing()

# sets
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

set(CMAKE_CXX_STANDARD 14)
set(BOXES_GAME_SRC_FILES
        src/logic/Colors.hxx src/logic/Box.hxx src/logic/Box.cxx src/logic/BoxStacker.hxx
        src/logic/BoxStacker.cxx src/logic/Stack.hxx src/logic/Stack.cxx src/logic/StackPopper.hxx src/logic/StackPopper.cxx src/logic/VerticalNeighbourCounter.hxx
        src/logic/VerticalNeighbourCounter.cxx src/logic/VerticalNeigbourCountResult.hxx src/logic/VerticalNeigbourCountResult.cxx src/logic/StackPopResult.hxx src/logic/StackPopResult.cxx src/logic/StackDivider.hxx
        src/logic/StackDivider.cxx src/logic/AdjacentNeighbourCounter.hxx src/logic/AdjacentNeighbourCounter.cxx src/logic/StackSet.hxx src/logic/StackSet.cxx src/components/BoxPosition.hxx
        src/components/BoxPosition.cxx src/logic/AdjacentNeighbourCountResult.hxx src/logic/AdjacentNeighbourCountResult.cxx src/delegates/TileExistsChecker.hxx src/delegates/TileExistsChecker.cxx src/logic/SameColorChecker.hxx
        src/logic/SameColorChecker.cxx src/logic/NeighboursInVicinityCounter.hxx src/logic/NeighboursInVicinityCounter.cxx src/logic/AdjacentPopper.hxx src/logic/AdjacentPopper.cxx src/logic/AdjacentPopperResult.hxx
        src/logic/AdjacentPopperResult.cxx src/logic/PoppedPositions.hxx src/logic/PoppedPositions.cxx src/logic/VerticalMover.hxx src/logic/VerticalMover.cxx src/logic/VerticalMovements.hxx
        src/logic/VerticalMovements.cxx src/logic/VerticalMovement.hxx src/logic/VerticalMovement.cxx src/logic/HorizontalMover.cxx src/logic/HorizontalMover.hxx src/logic/HorizontalMovements.cxx
        src/logic/HorizontalMovements.hxx src/delegates/WindowRefGetter.cxx src/delegates/WindowRefGetter.hxx src/logic/HorizontalMovement.cxx src/logic/HorizontalMovement.hxx src/view/Window.cxx
        src/view/Window.hxx src/view/WindowOpener.cxx src/view/WindowOpener.hxx src/decorators/GameLooper.cxx src/decorators/GameLooper.hxx src/view/WindowRenamer.cxx
        src/view/WindowRenamer.hxx src/delegates/WindowRefGetter.cxx src/delegates/WindowRefGetter.hxx src/view/BoxDrawer.cxx src/view/BoxDrawer.hxx src/view/PNGLoader.cxx
        src/view/PNGLoader.hxx src/view/PNG.cxx src/view/PNG.hxx src/view/PNGDrawer.cxx src/view/PNGDrawer.hxx src/delegates/PNGSurfaceGetter.cxx
        src/delegates/PNGSurfaceGetter.hxx src/view/RectBuilder.cxx src/view/RectBuilder.hxx src/view/PNGDimensionGetter.cxx src/view/PNGDimensionGetter.hxx src/components/Dimension.cxx
        src/components/Dimension.hxx src/components/DrawPosition.cxx src/components/DrawPosition.hxx src/view/WindowUpdater.cxx src/view/WindowUpdater.hxx src/view/IMGInitializer.cxx
        src/view/IMGInitializer.hxx src/logic/Vector2D.cxx src/logic/Vector2D.hxx src/delegates/BackgroundRendererEntityFactory.cxx src/delegates/BackgroundRendererEntityFactory.hxx src/decorators/LoopTerminator.cxx src/decorators/LoopTerminator.hxx src/view/StackSetEntityMaker.cxx src/view/StackSetEntityMaker.hxx
        src/view/WindowCleaner.cxx src/view/WindowCleaner.hxx src/systems/TerrainRendererSubSystem.cxx src/systems/TerrainRendererSubSystem.hxx src/view/Renderable.hxx src/view/Renderable.cxx
        src/view/WindowPositioner.cxx src/view/WindowPositioner.hxx src/view/PNGFactory.cxx src/view/PNGFactory.hxx src/systems/BackgroundRendererSubSystem.cxx src/systems/BackgroundRendererSubSystem.hxx
        src/systems/BoxRendererSubSystem.hxx src/systems/BoxRendererSubSystem.cxx src/view/SmokeAdder.hxx src/view/SmokeAdder.cxx src/view/WindowDimensionGetter.cxx src/view/WindowDimensionGetter.hxx
        src/EntityFactory.cxx src/view/BoxDrawingConfiguration.cxx src/view/BoxDrawingConfiguration.hxx src/EntityFactory.hxx src/systems/RenderingSystem.cxx src/systems/RenderingSystem.hxx
        src/components/BackgroundComponent.cxx src/components/BackgroundComponent.hxx src/systems/GameSystem.cxx src/systems/GameSystem.hxx src/view/DrawCanvas.cxx src/view/DrawCanvas.hxx
        src/components/Scale.cxx src/components/Scale.hxx src/systems/GameBeginZoomOut.cxx src/systems/GameBeginZoomOut.hxx src/systems/ZoomOutAnimationSystem.cxx src/systems/ZoomOutAnimationSystem.hxx
        src/view/TerrainRenderer.cxx src/view/TerrainRenderer.hxx src/view/ResourceUtil.cxx src/view/ResourceUtil.hxx src/components/TerrainComponent.cxx src/components/TerrainComponent.hxx
        src/decorators/MouseClickTracker.cxx src/decorators/MouseClickTracker.hxx src/components/MouseClicked.cxx src/components/MouseClicked.hxx src/view/BoxPositionCalculator.cxx src/view/BoxPositionCalculator.hxx
        tests/DisapperanceAnimationTests.cxx src/components/AnimationSet.cxx src/components/AnimationSet.hxx src/systems/RenderingSubSystem.cxx src/systems/RenderingSubSystem.hxx src/systems/AnimationSubSystem.cxx
        src/systems/AnimationSubSystem.hxx src/components/AnimationStep.cxx src/components/AnimationStep.hxx src/systems/TilePopperSystem.cxx src/systems/TilePopperSystem.hxx src/components/WillPop.cxx
        src/components/WillPop.hxx tests/FallDownTests.cxx src/systems/TileVerticalMover.cxx src/systems/TileVerticalMover.hxx src/components/Offset.cxx src/components/Offset.hxx
        src/logic/StackSetInserter.cxx src/logic/StackSetInserter.hxx src/systems/TileHorizontalMover.cxx src/systems/TileHorizontalMover.hxx tests/MergeBackTests.cxx src/delegates/SingleDataHolder.cxx
        src/delegates/SingleDataHolder.hxx src/delegates/SquaredDistanceModeler.cxx src/delegates/SquaredDistanceModeler.hxx src/logic/HorizontalStackInserter.cxx src/logic/HorizontalStackInserter.hxx
        src/logic/HorizontalStackInserterResult.cxx src/logic/HorizontalStackInserterResult.hxx src/logic/StackSetFactory.cxx src/logic/StackSetFactory.hxx src/logic/StackFactory.cxx src/logic/StackFactory.hxx src/delegates/CharToColorConverter.cxx
        src/delegates/CharToColorConverter.hxx src/systems/StackInsertionSystem.cxx src/systems/StackInsertionSystem.hxx src/GameConfig.cxx src/GameConfig.hxx
        src/delegates/MovementChecker.hxx src/delegates/MovementChecker.cxx src/view/GraphicsHolder.cxx src/view/GraphicsHolder.hxx
        src/delegates/PlainBackgroundMaker.cxx src/delegates/PlainBackgroundMaker.hxx
        src/delegates/LogoMaker.cxx src/delegates/LogoMaker.hxx
        src/delegates/BackgroundBoxesMaker.cxx src/delegates/BackgroundBoxesMaker.hxx src/components/Velocity.cxx src/components/Velocity.hxx src/systems/VelocitySystem.cxx src/systems/VelocitySystem.hxx src/view/StartButtonMaker.cxx src/view/StartButtonMaker.hxx src/decorators/AnyClickTracker.cxx src/decorators/AnyClickTracker.hxx


        src/systems/SoundSystem.cxx src/systems/SoundSystem.hxx src/components/Sound.cxx src/components/Sound.hxx src/components/Music.cxx src/components/Music.hxx src/delegates/MusicPlayer.cxx src/delegates/MusicPlayer.hxx src/delegates/SoundPlayer.cxx src/delegates/SoundPlayer.hxx src/systems/EndGameSystem.cxx src/systems/EndGameSystem.hxx src/delegates/BoxExistanceChecker.cxx src/delegates/BoxExistanceChecker.hxx tests/GuiTests.cxx src/systems/GuiRenderer.cxx src/systems/GuiRenderer.hxx src/components/TTFText.cxx src/components/TTFText.hxx src/systems/FontRenderingSubSystem.cxx src/systems/FontRenderingSubSystem.hxx src/view/TTFRenderer.cxx src/view/TTFRenderer.hxx tests/GameOverMakerTests.cxx src/view/GameOverMaker.cxx src/view/GameOverMaker.hxx)

#definitions
#add_definitions("-Wall -Wextra -pedantic-errors -Werror=return-type")

# includes/include directories
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_sdl2.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_boost.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_gtest.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_gmock.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/configure_entityx.cmake)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

# binaries/executables/libraries
add_library(boxesGame STATIC ${BOXES_GAME_SRC_FILES})

SET(MACOSX_BUNDLE_BUNDLE_NAME Robocubes)
add_executable(boxesGameExe main.cxx src/delegates/GameCleaner.cxx src/delegates/GameCleaner.hxx)
SET_TARGET_PROPERTIES(boxesGameExe PROPERTIES MACOSX_BUNDLE TRUE)

# linker
target_link_libraries(boxesGame ${Boost_LIBRARIES} ${SDL2_LIBRARY_SET} ${ENTITYX_BINARIES})
target_link_libraries(boxesGameExe boxesGame  ${Boost_LIBRARIES} ${SDL2_LIBRARY_SET} ${ENTITYX_BINARIES})


#tests

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/tests)


#packaging
