set(ENTITYX_ROOT "" CACHE PATH "Root to entityx.")
set(ENTITYX_BIN "" CACHE PATH "bin of entityx.")

find_package(EntityX REQUIRED)
include_directories(${ENTITYX_INCLUDE_DIR})

message("ENTITYX_INCLUDE_DIR : ${ENTITYX_INCLUDE_DIR}")
message("ENTITYX_BINARIES : ${ENTITYX_BINARIES}")

#link against ENTITYX_BINARIES