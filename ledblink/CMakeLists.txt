cmake_minimum_required(VERSION 3.12)

project(ledblink C)
set(CMAKE_C_STANDARD 99)

# The default setting is to expect that all libs are available
# at the same folder level as the application.  This can be
# changed by setting the cache variable BITLOOM_ROOT
# (cmake -D BITLOOM_ROOT=<path> ..)
# Cache variables can be viewed by "cmake -L"
set(BITLOOM_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/.." CACHE STRING "Root folder for Bitloom libs")
set(BITLOOM_HAL "${BITLOOM_ROOT}/bitloom-avr/avr_hal")

# Use the cross-compile version of add_executable defined in the toolchain
cc_add_executable(ledblink
        src/main.c
        blinktask/blinktask.h
        blinktask/blinktask.c
        avr_config/avr_port_config.c)

# The following directory includes the project specific configurations
# for the modules used.  Hence it needs to be available for all targets.
include_directories(${PROJECT_CONFIG_DIR})

cc_target_include_directories(ledblink PRIVATE ${BITLOOM_ROOT}/bitloom-core/include/hal)
cc_target_include_directories(ledblink PRIVATE blinktask)

add_subdirectory(${BITLOOM_ROOT}/bitloom-core/modules/scheduler libs/scheduler)
add_subdirectory(${BITLOOM_HAL} libs/hal)

cc_target_link_libraries(ledblink scheduler)
cc_target_link_libraries(ledblink hal)