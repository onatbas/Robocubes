set(CUCUMBER_ROOT "" CACHE PATH "Cucumber root path")

set(CUCUMBER_INCLUDE_DIR ${CUCUMBER_ROOT}/include)
include_directories(${CUCUMBER_INCLUDE_DIR})

set(CUCUMBER_BINARY_DIR ${CUCUMBER_ROOT}/build/src)
file(GLOB CUCUMBER_BINARIES "${CUCUMBER_BINARY_DIR}/libcucumber-cpp.a")
message("Cucumber binaries: ${CUCUMBER_BINARIES}")
#link against ${CUCUMBER_BINARIES}