cmake_minimum_required(VERSION 3.15)
project(MyOwnCPP)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")

include_directories(src)

add_executable(Main main.cpp)
target_link_libraries(Main CONTAINERS_LIB FUNCTIONS_LIB)

add_subdirectory(src)
message("Project by: Deodato Bastos")