# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(TrafficLightFSM)

set(CMAKE_CXX_STANDARD 17)
set(SRC_DIR "${CMAKE_SOURCE_DIR}/src")

# executable
add_executable(traffic_fsm
    ${SRC_DIR}/traffic_fsm.cpp
    # if you split out main.cpp, list it here too
)

# install (optional)
install(TARGETS traffic_fsm DESTINATION bin)

# (optional) add tests
# enable_testing()
# add_subdirectory(tests)
