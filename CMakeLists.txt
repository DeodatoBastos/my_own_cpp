cmake_minimum_required(VERSION 3.15)
project(MyOwnCPP)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/build")

add_subdirectory(src)
message("Project by: Deodato Bastos")