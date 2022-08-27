file(GLOB CONT_SRC *.cpp)

add_library(CONTAINERS_LIB SHARED ${CONT_SRC})
target_include_directories(CONTAINERS_LIB PUBLIC .)