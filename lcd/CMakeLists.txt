cmake_minimum_required(VERSION 3.12)

project(ldc C)
set(CMAKE_C_STANDARD 99)

# The default setting is to expect that all libs are available
# at the same folder level as the application.  This can be
# changed by setting the cache variable BITLOOM_ROOT
# (cmake -D BITLOOM_ROOT=<path> ..)
# Cache variables can be viewed by "cmake -L"
set(BITLOOM_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/.." CACHE STRING "Root folder for Bitloom libs")

# BITLOOM_HAL needs to be set in order for the project to build correctly.
# For AVR, this is currently set in the toolchain file.

# BITLOOM_CONFIG should be set to the directory containing the configuration
# for the project's target environment as well as the processor specifics.
set(BITLOOM_CONFIG ${CMAKE_CURRENT_SOURCE_DIR}/${CONFIG})

# Output BitLoom specific folders
message(STATUS "CMAKE SOURCE: ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "BITLOOM_ROOT: ${BITLOOM_ROOT}")
message(STATUS "BITLOOM_HAL: ${BITLOOM_HAL}")
message(STATUS "BITLOOM_CONFIG: ${BITLOOM_CONFIG}")

# Make sure that all required variables have been set
if (NOT BITLOOM_HAL)
    message(FATAL_ERROR "BITLOOM_HAL directory not specified.")
endif(NOT BITLOOM_HAL)

if (NOT CONFIG)
    message(FATAL_ERROR "CONFIG directory not specified.")
endif(NOT CONFIG)

# Use the cross-compile version of add_executable defined in the toolchain
cc_add_executable(lcd
        src/main.c
        )

# The following directory includes the project specific configurations
# Hence it needs to be available for all targets.
include_directories(${BITLOOM_CONFIG})

cc_target_include_directories(lcd PRIVATE ${BITLOOM_ROOT}/bitloom-core/include)

add_subdirectory(${BITLOOM_ROOT}/bitloom-core/src/scheduler libs/core/scheduler)
add_subdirectory(${BITLOOM_HAL}/src/timer libs/hal/timer)
add_subdirectory(${BITLOOM_HAL}/src/pin_digital_io libs/hal/pin_digital_io)
add_subdirectory(${BITLOOM_CONFIG}/config libs/config)

cc_target_link_libraries(lcd scheduler)
cc_target_link_libraries(lcd timer)
cc_target_link_libraries(lcd pin_digital_io)
cc_target_link_libraries(lcd config)
